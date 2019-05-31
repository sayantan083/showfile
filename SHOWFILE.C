#include<stdio.h>
#include<windows.h>
void draw_box(int,int,int,int);
//Defines gotoxy() for ANSI C compilers.
void gotoxy(short x, short y) {
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
int main()
{
  int r=3,c=2,count=1;
  char ch;
  FILE *fp;
  system("cls");
  fp=fopen("calender.c","r");
  if(fp==NULL)
  {
   printf("Unable to open file");
   exit(0);
  }
  printf("CALENDER.C %68d",count);
  draw_box(1,79,2,24);
  while((ch=fgetc(fp))!=EOF)
  {
    if(ch!='\n')
    {
     gotoxy(c,r);
     printf("%c",ch);
     c++;
    }
    else
    {
     r++;
     c=2;
     if(r>23)
     {
      gotoxy(1,25);
      system("pause");
      count++;
      system("cls");
      gotoxy(1,1);
      printf("CALENDAR.C %68d",count);
      draw_box(1,79,2,24);
      r=3;
      c=2;
     }
    }
  }
  fclose(fp);
  system("cls");
  system("pause");
  return 0;
}
void draw_box(int xmin,int xmax,int ymin,int ymax)
{
 int i,j;
 gotoxy(xmin,ymin);
 printf("%c",218);
 gotoxy(xmax,ymin);
 printf("%c",191);
 gotoxy(xmin,ymax);
 printf("%c",192);
 gotoxy(xmax,ymax);
 printf("%c",217);
 for(i=xmin+1,j=ymin+1;i<xmax;i++,j++)
  {
    gotoxy(i,ymin);
    printf("%c",196);
   if(j<ymax)
    {
     gotoxy(xmin,j);
     printf("%c",179);
    }
  }
 for(i=xmax-1,j=ymax-1;i>xmin;i--,j--)
  {
    gotoxy(i,ymax);
    printf("%c",196);
    if(j>ymin)
    {
     gotoxy(xmax,j);
     printf("%c",179);
    }
  }
}
