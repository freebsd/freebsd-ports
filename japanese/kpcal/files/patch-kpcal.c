--- kpcal.c.orig
+++ kpcal.c
@@ -5,6 +5,8 @@
  */
 
 #include <stdio.h>
+#include <stdlib.h>
+#include <unistd.h>
 #include <ctype.h>
 #include <time.h>
 #include <string.h>
@@ -28,6 +30,7 @@
 static char daynum_font[64] = DAYNUM_DEFAULT_FONT;
 
 extern void ConvertString();
+extern void pmonth();
 
 FILE *cfp = NULL;
 int year;
@@ -35,7 +38,7 @@
 
 char *getenv();
 
-main(argc, argv)
+int main(argc, argv)
      int argc;
      char **argv;
 {
@@ -46,7 +49,7 @@
   register char *cp;
   char *cfile = NULL;
   char cbuf[80];
-  long t, time();
+  time_t t, time();
   int errflg = 0;
   int nocal = 0;
   int m;
@@ -86,7 +89,7 @@
     exit(1);
   }
 
-  t = time((long *)0);
+  t = time((time_t *)0);
   lt = localtime(&t);
 
   /*
@@ -150,7 +153,7 @@
 /*
  * pmonth - do calendar for month "m"
  */
-pmonth(m)
+void pmonth(m)
 int m;
 {
   register char **s;
