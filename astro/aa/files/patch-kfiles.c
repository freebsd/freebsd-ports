--- kfiles.c.orig	Sat Aug  9 17:01:51 2003
+++ kfiles.c	Fri Feb 29 16:51:58 2008
@@ -3,9 +3,8 @@
  * or file containing orbital elements.
  */
 
-#if __BORLANDC__
 #include <stdlib.h>
-#endif
+#include <stdio.h>
 
 #include "kep.h"
 
@@ -26,8 +25,8 @@
 
 extern char *intfmt, *strfmt;/* see dms.c */
 
-static char starnam[80] = {'s','t','a','r','.','c','a','t','\0'};
-static char orbnam[80] = {'o','r','b','i','t','.','c','a','t','\0'};
+static char starnam[80];
+static char orbnam[80];
 static int linenum = 1;
 
 /* Read initialization file aa.ini
@@ -67,13 +66,36 @@
 int kinit()
 {
 double a, b, fl, co, si, u;
-FILE *f, *fopen();
+FILE *f = NULL, *fopen();
 char s[84];
+char *inifile = NULL, *home = getenv("HOME");
 
 printf( "\n\tSteve Moshier's Ephemeris Program v5.6\n\n" );
 printf( "Planetary and lunar positions approximate DE404.\n" );
 
-f = fopen( "aa.ini", "r" );
+ snprintf(starnam, 80, "%%DATADIR%%/star.cat");
+ snprintf(orbnam, 80, "%%DATADIR%%/orbit.cat"); 
+
+/* User inifile */
+ if(home){
+   inifile = strdup(home);
+   realloc(inifile, strlen(home) + strlen("/.aa.ini") + 1);
+   strcat(inifile,"/.aa.ini");
+   f = fopen( inifile, "r" );
+ }
+
+ /* System inifile */
+ if(!f){
+   inifile = "%%PREFIX%%/etc/aa.ini";
+   f = fopen( inifile, "r" );
+ }
+
+  if (f){
+   printf("\nUsing inifile %s\n", inifile);
+ } else {
+   printf("\nNo inifile.\n");
+ }
+
 if( f )
 	{
 	fgets( s, 80, f );
