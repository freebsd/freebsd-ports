--- gb2ps.h.orig	1992-08-23 11:38:03.000000000 +0800
+++ gb2ps.h	2013-09-26 21:06:36.000000000 +0800
@@ -11,6 +11,9 @@
  *      and THERE IS NO WARRANTY FOR THIS PROGRAM.
  ****************************************************************************/
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
+#include <ctype.h>
 
 #define CHAR_LIMIT 2
 #ifndef CFONT
@@ -81,6 +84,7 @@ extern int	endpage_flag;
 extern int	format_flag;
 extern int	pageno_flag;
 extern int	coverpage_flag;
+extern void coverpage();
 extern int	pagecounter;
 extern int	linecounter;
 extern float	line_h[];
@@ -90,14 +94,19 @@ extern FILE	*in, *out;
 extern FILE	*cfont;
 extern float	H,V;
 
-extern int ASCshow();
-extern int put_ASC();
-extern int put_CH();
+extern void ASCshow();
+extern void put_ASC();
+extern void put_CH();
 extern int putChar();
-extern int putString();
-extern int DefCHdict();
-extern int AnalyseDoc();
-
+extern void putString();
+extern void DefCHdict();
+extern void AnalyseDoc();
+
+extern void ps_end();
+extern void end_page();
+extern void begin_page();
+extern void ps_header();
+extern void init_page();
 extern int init();
-extern int cleanup();
+extern void cleanup();
 extern int readchar();
