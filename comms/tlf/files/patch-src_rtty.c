--- src/rtty.c.orig	Sat Jul 10 21:41:49 2004
+++ src/rtty.c	Sun Jul 11 00:52:01 2004
@@ -72,7 +72,7 @@

 int ry_addtext(char *line) {

-extern char ry_term[][];
+//extern char ry_term[][];

 int k, m, j;
 char *ptr;
@@ -137,7 +137,7 @@
 int show_rtty(void) {

 extern int use_rxvt;
-extern char ry_term[][];
+//extern char ry_term[][];
 extern int trxmode;

 if (trxmode != DIGIMODE)
@@ -169,7 +169,7 @@

 extern char hiscall[];
 extern int miniterm;
-extern char ry_term[][];
+//extern char ry_term[][];

 int i = 0;
 char line[40];
