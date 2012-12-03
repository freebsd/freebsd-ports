--- fpr/fpr.c.orig	1994-05-27 14:31:21.000000000 +0200
+++ fpr/fpr.c	2012-12-03 10:50:48.000000000 +0100
@@ -45,6 +45,7 @@
 #endif /* not lint */
 
 #include <stdio.h>
+#include <stdlib.h>
 
 #define BLANK ' '
 #define TAB '\t'
@@ -80,12 +81,13 @@
 int maxpos;
 int maxcol;
 
-extern char *malloc();
-extern char *calloc();
-extern char *realloc();
-
-
+void init();
+void mygettext();
+void flush();
+void savech(int);
+void nospace();
 
+int
 main()
 {
   register int ch;
@@ -124,7 +126,7 @@
 
   while ( ! ateof)
     {
-      gettext();
+      mygettext();
       ch = getchar();
       if (ch == EOF)
 	{
@@ -176,6 +178,7 @@
 
 
 
+void
 init()
 {
   register COLUMN *cp;
@@ -210,7 +213,8 @@
 
 
 
-gettext()
+void
+mygettext()
 {
   register int i;
   register char ateol;
@@ -283,8 +287,8 @@
 
 
 
-savech(col)
-int col;
+void
+savech(int col)
 {
   register char ch;
   register int oldmax;
@@ -340,6 +344,7 @@
 
 
 
+void
 flush()
 {
   register int i;
@@ -403,6 +408,7 @@
 
 
 
+void
 nospace()
 {
   fputs("Storage limit exceeded.\n", stderr);
