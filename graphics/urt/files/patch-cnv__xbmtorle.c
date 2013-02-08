--- cnv/xbmtorle.c.orig	1992-04-30 23:01:54.000000000 +0900
+++ cnv/xbmtorle.c	2012-10-16 01:02:29.000000000 +0900
@@ -29,6 +29,7 @@
 xbmtorle()				Tag the file.
 */
 
+#include <string.h>
 #include "rle.h"
 
 #define MAX_LINE 500
@@ -65,7 +66,7 @@
  * 	Reads the bitmap, then builds an RLE image with one pixel per
  * 	bit in the input.
  */
-void
+int
 main( argc, argv )
 int argc;
 char **argv;
