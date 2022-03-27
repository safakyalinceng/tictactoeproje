#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char tahta[3][3];
const char OYUNCU = 'X';
const char BILGISAYAR = 'O';

void tahtayiSifirla();
void tahtayaYaz();
int bosluklariKontrolEt();
void oyuncuHamlesi();
void bilgisayarHamlesi();
char kazananKontrolEt();
void kazananYaz(char);

int main()
{
   char kazanan = ' ';
   char yanit = ' ';

   do
   {
      kazanan = ' ';
      yanit = ' ';
      tahtayiSifirla();

      while(kazanan == ' ' && bosluklariKontrolEt() != 0)
      {
         tahtayaYaz();

         oyuncuHamlesi();
         kazanan = kazananKontrolEt();
         if(kazanan != ' ' || bosluklariKontrolEt() == 0)
         {
            break;
         }

         bilgisayarHamlesi();
         kazanan = kazananKontrolEt();
         if(kazanan != ' ' || bosluklariKontrolEt() == 0)
         {
            break;
         }
      }

     tahtayaYaz();
      kazananYaz(kazanan);

      printf("\nTekrar oynamak ister misiniz? (E/H): ");
      scanf("%c");
      scanf("%c", &yanit);
     yanit = toupper(yanit);
   } while (yanit == 'E');

   printf("Oynadiginiz icin tesekkurler!");

   return 0;
}

void tahtayiSifirla()
{
    for(int i = 0; i < 3; i++)
   {
       for(int j = 0; j < 3; j++)
      {
         tahta[i][j] = ' ';
      }
   }
}
void tahtayaYaz()
{
   printf(" %c | %c | %c ", tahta[0][0], tahta[0][1], tahta[0][2]);
   printf("\n---|---|---\n");
   printf(" %c | %c | %c ", tahta[1][0], tahta[1][1], tahta[1][2]);
   printf("\n---|---|---\n");
   printf(" %c | %c | %c ", tahta[2][0], tahta[2][1], tahta[2][2]);
   printf("\n");
}
int bosluklariKontrolEt()
{
   int bosluklar = 9;

    for(int i = 0; i < 3; i++)
   {
       for(int j = 0; j < 3; j++)
      {
         if(tahta[i][j] != ' ')
         {
            bosluklar--;
         }
      }
   }
   return bosluklar;
}
void oyuncuHamlesi()
{
   int x;
   int y;

   do
   {
      printf("Satir giriniz (1-3): ");
      scanf("%d", &x);
      x--;
      printf("Sutun giriniz (1-3): ");
      scanf("%d", &y);
      y--;

      if(tahta[x][y] != ' ')
      {
         printf("Gecersiz hamle!\n");
      }
      else
      {
         tahta[x][y] = OYUNCU;
         break;
      }
   } while (tahta[x][y] != ' ');
   
}
void bilgisayarHamlesi()
{
  
   srand(time(0));
   int x;
   int y;

   if(bosluklariKontrolEt() > 0)
   {
      do
      {
         x = rand() % 3;
         y = rand() % 3;
      } while (tahta[x][y] != ' ');
      
      tahta[x][y] = BILGISAYAR;
   }
   else
   {
      kazananYaz(' ');
   }
}
char kazananKontrolEt()
{
      for(int i = 0; i < 3; i++)
   {
      if(tahta[i][0] == tahta[i][1] && tahta[i][0] == tahta[i][2])
      {
         return tahta[i][0];
      }
   }
     for(int i = 0; i < 3; i++)
   {
      if(tahta[0][i] == tahta[1][i] && tahta[0][i] == tahta[2][i])
      {
         return tahta[0][i];
      }
   }
   if(tahta[0][0] == tahta[1][1] && tahta[0][0] == tahta[2][2])
   {
      return tahta[0][0];
   }
   if(tahta[0][2] == tahta[1][1] && tahta[0][2] == tahta[2][0])
   {
      return tahta[0][2];
   }

   return ' ';
}
void kazananYaz(char kazanan)
{
   if(kazanan == OYUNCU)
   {
      printf("Tebrikler kazandiniz!");
   }
   else if(kazanan == BILGISAYAR)
   {
      printf("Uzgunuz kaybettiniz!");
   }
   else{
      printf("Berabere!");
   }
}
