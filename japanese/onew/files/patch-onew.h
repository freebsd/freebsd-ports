--- onew.h.orig	1994-06-24 10:27:13.000000000 +0900
+++ onew.h	2013-11-03 22:44:02.000000000 +0900
@@ -21,7 +21,7 @@
 
 #define LINESIZE	1024
 typedef unsigned char Uchar;
-typedef Uchar Linebuff[LINESIZE];
+typedef char Linebuff[LINESIZE];
 typedef char Mssgbuff[LINESIZE];
 typedef	char Pathname[LINESIZE];
 
@@ -272,3 +272,23 @@
 #define JVIM_RARROW	0xffffff83
 #define JVIM_HENKAN	0xffffff9f
 
+int ouiGETCHAR(void);
+int ouiPEEKCHAR(int *);
+int ouiGOT_2BCHAR(char *, int, int);
+int ouiDISP_ROMKANMODE(char *, char *, int); 
+int ouiDISP_KANAHALVES(char *);
+int ouiKANAKAN(int);
+int ouiDISP_KANAKANB(char *, char *, char *, char *);
+int ouiKAKUTEI(int);
+int ouiBEEP(int);
+int ouiMESSAGE_COLS(void);
+int ouiMESSAGE(int, char *, ...);
+int Onew_modef(char **, char *, char **, char *);
+void Onew_putmsg(int, char *, ...);
+void Onew_putmsg_sys(int, char *, ...);
+void Onew_putmsg_retain(int, char *, ...);
+void Onew_putmode(char *, char *);
+
+int ONEW_getch0(int);
+
+int oeiJisyoTouroku(int, char *, char *, char *);
