--- cnv/rletoascii.c.orig	1992-01-21 02:29:09.000000000 +0900
+++ cnv/rletoascii.c	2012-10-16 00:21:43.000000000 +0900
@@ -21,6 +21,7 @@
  */
 
 #include <stdio.h>
+#include <string.h>
 #include "rle.h"
 
 typedef FILE	*FILPTR;
@@ -59,7 +60,7 @@
  */
 static char default_asciistr[] = "@BR*#$PX0woIcv:+!~\"., ";
 
-void
+int
 main(argc, argv)
 int  argc;
 char *argv[];
