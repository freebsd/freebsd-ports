--- fpr/fpr.c.orig	Fri May 27 14:31:21 1994
+++ fpr/fpr.c	Sat Jun 12 23:49:50 2004
@@ -45,6 +45,7 @@
 #endif /* not lint */
 
 #include <stdio.h>
+#include <stdlib.h>
 
 #define BLANK ' '
 #define TAB '\t'
@@ -80,9 +81,6 @@
 int maxpos;
 int maxcol;
 
-extern char *malloc();
-extern char *calloc();
-extern char *realloc();
 
 
 
@@ -124,7 +122,7 @@
 
   while ( ! ateof)
     {
-      gettext();
+      mygettext();
       ch = getchar();
       if (ch == EOF)
 	{
@@ -210,7 +208,7 @@
 
 
 
-gettext()
+mygettext()
 {
   register int i;
   register char ateol;
