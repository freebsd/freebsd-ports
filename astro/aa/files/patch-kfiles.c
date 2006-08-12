--- kfiles.c.orig	Sat Aug  9 17:01:51 2003
+++ kfiles.c	Fri Aug 11 18:51:05 2006
@@ -3,9 +3,7 @@
  * or file containing orbital elements.
  */
 
-#if __BORLANDC__
 #include <stdlib.h>
-#endif
 
 #include "kep.h"
 
@@ -67,13 +65,33 @@
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
