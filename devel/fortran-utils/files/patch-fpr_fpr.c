--- fpr/fpr.c.orig	1994-05-27 12:31:21 UTC
+++ fpr/fpr.c
@@ -45,6 +45,7 @@ static char sccsid[] = "@(#)fpr.c	8.1 (B
 #endif /* not lint */
 
 #include <stdio.h>
+#include <stdlib.h>
 
 #define BLANK ' '
 #define TAB '\t'
@@ -80,12 +81,13 @@ COLUMN *line;
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
@@ -124,7 +126,7 @@ main()
 
   while ( ! ateof)
     {
-      gettext();
+      mygettext();
       ch = getchar();
       if (ch == EOF)
 	{
@@ -176,6 +178,7 @@ main()
 
 
 
+void
 init()
 {
   register COLUMN *cp;
@@ -210,7 +213,8 @@ init()
 
 
 
-gettext()
+void
+mygettext()
 {
   register int i;
   register char ateol;
@@ -283,8 +287,8 @@ gettext()
 
 
 
-savech(col)
-int col;
+void
+savech(int col)
 {
   register char ch;
   register int oldmax;
@@ -340,6 +344,7 @@ int col;
 
 
 
+void
 flush()
 {
   register int i;
@@ -403,6 +408,7 @@ flush()
 
 
 
+void
 nospace()
 {
   fputs("Storage limit exceeded.\n", stderr);
