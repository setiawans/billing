
#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <windows.h>
#include <math.h>
#include <dos.h>
#include <stdlib.h>
#include <time.h>
//------------------------------------------------------------------------------
int tampilan();
int cek();
int cek1();
int cek_kolom();
int tabell();
int konversi();
//------------------------------------------------------------------------------
time_t satu[5][5];
time_t dua;
time_t t;
int jam,menit,detik,menit1,detik1,jm;
//------------------------------------------------------------------------------
int tarif,i,j,a,b,klm,baris,pilihan,ini,itu;
float bayar,kembalian,total=0;
char pilih,kolom;
FILE *in;
char x[10];
int tabel[5][5]={{0}};
float waktu[5][5]={{0}};
//------------------------------------------------------------------------------
void main()
{
   if((in = fopen("history.txt","w"))== NULL){
			fprintf(stderr,"Cannot open input file.\n");
   }
	fflush(stdin);
	fputs("\t\t <=={ Tampilan Timer }==> ",in);
	fputs("\n\n",in);
	fclose(in);

	tampilan();

balik:
   clrscr();
   printf("\t\t       PILIHAN MENU\n\n");
   printf("\t\t 1. Masukkan Komputer User\n");
   printf("\t\t 2. Lihat Komputer yang Tersedia\n");
   printf("\t\t 3. Lihat Timer\n");
   printf("\t\t 4. Penghentian Komputer User\n");
   printf("\t\t 5. Keluar\n\n");
   printf("\t\t Press Key  ");
   scanf("%d",&pilihan);
//------------------------------------------------------------------------------
tabel1:
   clrscr();
   if(pilihan==1){
      tabell();
      printf("<1>Next  <2>Back    --->  ");
      scanf("%d",&ini);
      if(ini==2){
      	goto balik;
      }
      else if(ini==1){
      	goto neks;
      }
      else{
      	goto tabel1;
      }
   neks:
   	printf("Masukkan baris = ");
   	scanf("%d",&baris);
   	fflush(stdin);
   	printf("Masukkan kolom = ");
   	scanf("%c",&kolom);

   	if(cek_kolom()==0){
      	goto tabel1;
      }
      if(cek()==0){
      	goto tabel1;
      }

   	printf("Masukkan Angka kecuali 0 untuk mengaktifkan komputer = ");
   	scanf("%d",&tabel[baris][klm]);
      satu[baris][kolom] = time(NULL);

      if((in = fopen("history.txt","a"))== NULL){
			fprintf(stderr,"Cannot open input file.\n");
		}
      time(&t);
      konversi();
      fputs(x,in);
		fputs(ctime(&t),in);
      fclose(in);
   	goto balik;
   }
//------------------------------------------------------------------------------
   else if(pilihan==2){
      tabell();
      getch();
      goto balik;
   }
//------------------------------------------------------------------------------
   else if(pilihan==3){
   	system("history.txt");
      goto balik;
   }
//------------------------------------------------------------------------------
   else if(pilihan==4){
   tabel2:
   	clrscr();
      tabell();
      printf("<1>Next  <2>Back    --->  ");
      scanf("%d",&itu);
      if(itu==2){
      	goto balik;
      }
      else if(itu==1){
      	goto next;
      }
      else{
      	goto tabel2;
      }
   next:
   	printf("Masukkan baris = ");
   	scanf("%d",&baris);
   	fflush(stdin);
   	printf("Masukkan kolom = ");
   	scanf("%c",&kolom);

   	if(cek_kolom()==0){
      	goto tabel2;
      }
      if(cek1()==0){
      	goto tabel2;
      }
   lagi:
   	printf("Masukkan Angka [0] untuk menonaktifkan komputer = ");
   	scanf("%d",&tabel[baris][klm]);
      if(tabel[baris][klm]!=0){
      	goto lagi;
      }
      dua = time(NULL);
      PlaySound(TEXT("SMSVoice.wav"), NULL, SND_FILENAME);
//------------------------------------------------------------------------------
		jm = difftime(dua,satu[baris][kolom]);
		jam = jm / 3600;
      menit1 = jm % 3600;
      menit = menit1 / 60;
      detik1 = jm % 3600;
      detik = detik1 % 60;
      printf("Lama Waktu    = %d jam %d menit %d detik\n",jam,menit,detik);

      if(difftime(dua,satu[baris][kolom]) <= 500){
      	total = 500;
      }
      else if(difftime(dua,satu[baris][kolom]) > 500 && difftime(dua,satu[baris][kolom]) < 1800){
      	total = 0.5 * tarif;
      }
      else if(difftime(dua,satu[baris][kolom]) >= 1800 && difftime(dua,satu[baris][kolom]) <= 3600){
      	total = tarif;
      }
      else{
      	total = difftime(dua,satu[baris][kolom]) / 3600 * tarif;
      }
      printf("Total Bayar   = %g\n",total);
      printf("Masukkan Uang = ");scanf("%f",&bayar);
      kembalian = bayar - total;
      printf("Kembalian     = %g",kembalian);
      getch();
   	goto balik;
   }
//------------------------------------------------------------------------------
   else if(pilihan==5){
   	exit(1);
   }
   else{
   	goto balik;
   }
}
//------------------------------------------------------------------------------
int tampilan()
{
	for(i=2; i<15; i++){
   	gotoxy(12,1);textcolor(i);cprintf(" ******    **  **      **      **  **    **    ******* ");
		gotoxy(12,2);textcolor(i);cprintf(" **    **  **  **      **      **  ****  **  **        ");
		gotoxy(12,3);textcolor(i);cprintf(" ******    **  **      **      **  **  ****  **    *** ");
		gotoxy(12,4);textcolor(i);cprintf(" **    **  **  **      **      **  **   ***  **      * ");
		gotoxy(12,5);textcolor(i);cprintf(" ******    **  ******  ******  **  **    **    ******* ");
      Sleep(250);
   }
   Sleep(250);
   gotoxy(6,7);textcolor(14);cprintf(" **          **   *******    **  **  *******      ******    **     ");
   Sleep(250);
	gotoxy(6,8);textcolor(14);cprintf(" **    **    **          **  ****    **     **  **      **  ****** ");
   Sleep(250);
	gotoxy(6,9);textcolor(14);cprintf(" **  **  **  **    ********  **      **     **  **********  **     ");
   Sleep(250);
	gotoxy(6,10);textcolor(14);cprintf(" **  **  **  **  **      **  **      **     **  **          **     ");
   Sleep(250);
	gotoxy(6,11);textcolor(14);cprintf("   **      **    **      **  **      **     **  **      **  **     ");
   Sleep(250);
	gotoxy(6,12);textcolor(14);cprintf("   **      **      ********  **      **     **    ******      **** ");
   Sleep(250);

   gotoxy(30,14);printf("Masukkan Tarif Hari ini");
   gotoxy(38,16);scanf("%d",&tarif);
   fflush(stdin);
   gotoxy(15,19);printf("Apakah Anda Setuju Menginstal Program ini? (Y/N)... ");
   scanf("%c",&pilih);
   if(pilih=='y' || pilih=='Y')
   {
   	goto lanjut;
   }
   else
   {
		exit(1);
   }
//------------------------------------------------------------------------------
lanjut:
   gotoxy(5,22);printf("%c",201);
	gotoxy(5,22);printf("%c",201);
	gotoxy(5,23);printf("%c",186);
	gotoxy(5,24);printf("%c",200);
	gotoxy(54,22);printf("%c",187);
	gotoxy(54,23);printf("%c",186);
	gotoxy(54,24);printf("%c",188);
	for(int u1=6;u1<54;u1++)
   {
   	gotoxy(u1,22);printf("%c",205);
   }
   printf("");
	for(int u2=6;u2<54;u2++){
   	gotoxy(u2,24);printf("%c",205);
   }
	for (int ui=1;ui<=100;ui++){
   	gotoxy(56,23);cout<<ui<<"%";
		if (ui%3==0){
			for(int l=1;l<ui/2;l++){
      		gotoxy(5+l,23);textcolor(12);cprintf("%c",219);
  				Sleep(10);
         }
  		}
 	}
   return 0;
}
//------------------------------------------------------------------------------
int cek()
{
	if(tabel[baris][klm]!=0){
   	printf("Maaf Komputer Telah Terpakai \n");
      Sleep(2000);
      return 0;
   }
   return 1;
}
//------------------------------------------------------------------------------
int cek1()
{
	if(tabel[baris][klm]==0){
   	printf("Maaf Komputer Belum Aktif \n");
      Sleep(2000);
      return 0;
   }
   return 1;
}
//------------------------------------------------------------------------------
int tabell()
{
	printf("\t\t\t      TAMPILAN KOMPUTER USER   \n\n\n");
   printf("     A       B       C       D       E           TARIF PER/JAM \n\n");
   for(i=0; i<4; i++){
   	printf("%d ",i);
   	for(j=0; j<5; j++){
     		if(tabel[i][j]==0){
     			if(i==0){
           		if(i==0 && j<4){
     					printf("[KOM %d] ",j+1);
        			}
           		if(i==0 && j==4){
              		printf("[KOM %d]",j+1);
                  printf("            [%d] ",tarif);
           		}
        		}
        		if(i==1 && j<4){
     				printf("[KOM %d] ",j+6);
        		}
        		if(i==1 && j==4){
     				printf("[KOM%d] ",j+6);
        		}
        		if(i==2){
     				printf("[KOM%d] ",j+11);
        		}
        		if(i==3){
     				printf("[KOM%d] ",j+16);
        		}
			}
        	if(tabel[i][j]!=0){
     			if(i==0){
           		if(i==0 && j<4){
     					textcolor(12);cprintf("[KOM %d] ",j+1);
        			}
           		if(i==0 && j==4){
              		textcolor(12);cprintf("[KOM %d]",j+1);
                  printf("            [%d] ",tarif);
           		}
        		}
        		if(i==1 && j<4){
     				textcolor(12);cprintf("[KOM %d] ",j+6);
        		}
        		if(i==1 && j==4){
     				textcolor(12);cprintf("[KOM%d] ",j+6);
        		}
        		if(i==2){
     				textcolor(12);cprintf("[KOM%d] ",j+11);
        		}
        		if(i==3){
     				textcolor(12);cprintf("[KOM%d] ",j+16);
        		}
			}
     	}
     	printf("\n\n");
   }
   return 0;
}
//------------------------------------------------------------------------------
int cek_kolom()
{
	if(kolom=='a' || kolom=='A'){
		klm=0;
	}
	else if(kolom=='b' || kolom=='B'){
		klm=1;
	}
	else if(kolom=='c' || kolom=='C'){
		klm=2;
	}
	else if(kolom=='d' || kolom=='D'){
		klm=3;
	}
	else if(kolom=='e' || kolom=='E'){
		klm=4;
	}
   else{
   	printf("Maaf Anda Melebihi Batas Kolom Maksimal");
      Sleep(2000);
   	return 0;
   }
   return 1;
}
//------------------------------------------------------------------------------
int konversi()
{
	if(baris==0 && kolom=='a' || kolom=='A'){
		strcpy(x,"KOM1  = ");
	}
	else if(baris==0 && kolom=='b' || kolom=='B'){
		strcpy(x,"KOM2  = ");
	}
   else if(baris==0 && kolom=='c' || kolom=='C'){
		strcpy(x,"KOM3  = ");
	}
   else if(baris==0 && kolom=='d' || kolom=='D'){
		strcpy(x,"KOM4  = ");
	}
   else if(baris==0 && kolom=='e' || kolom=='E'){
		strcpy(x,"KOM5  = ");
	}
   else if(baris==1 && kolom=='a' || kolom=='A'){
		strcpy(x,"KOM6  = ");
	}
	else if(baris==1 && kolom=='b' || kolom=='B'){
		strcpy(x,"KOM7  = ");
	}
   else if(baris==1 && kolom=='c' || kolom=='C'){
		strcpy(x,"KOM8  = ");
	}
   else if(baris==1 && kolom=='d' || kolom=='D'){
		strcpy(x,"KOM9  = ");
	}
   else if(baris==1 && kolom=='e' || kolom=='E'){
		strcpy(x,"KOM10 = ");
	}
   else if(baris==2 && kolom=='a' || kolom=='A'){
		strcpy(x,"KOM11 = ");
	}
	else if(baris==2 && kolom=='b' || kolom=='B'){
		strcpy(x,"KOM12 = ");
	}
   else if(baris==2 && kolom=='c' || kolom=='C'){
		strcpy(x,"KOM13 = ");
	}
   else if(baris==2 && kolom=='d' || kolom=='D'){
		strcpy(x,"KOM14 = ");
	}
   else if(baris==2 && kolom=='e' || kolom=='E'){
		strcpy(x,"KOM15 = ");
	}
   else if(baris==3 && kolom=='a' || kolom=='A'){
		strcpy(x,"KOM16 = ");
	}
	else if(baris==3 && kolom=='b' || kolom=='B'){
		strcpy(x,"KOM17 = ");
	}
   else if(baris==3 && kolom=='c' || kolom=='C'){
		strcpy(x,"KOM18 = ");
	}
   else if(baris==3 && kolom=='d' || kolom=='D'){
		strcpy(x,"KOM19 = ");
	}
   else if(baris==3 && kolom=='e' || kolom=='E'){
		strcpy(x,"KOM20 = ");
	}
   return 0;
}
