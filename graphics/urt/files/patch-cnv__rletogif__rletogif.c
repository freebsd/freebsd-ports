--- cnv/rletogif/rletogif.c.orig	1992-04-30 23:15:57.000000000 +0900
+++ cnv/rletogif/rletogif.c	2012-10-16 00:28:02.000000000 +0900
@@ -29,6 +29,7 @@
  */
 
 #include <stdio.h>
+#include <string.h>
 #include "rle.h"
 #include "rletogif.h"
 
@@ -44,7 +45,7 @@
 int get_color_bits();
 void GIFEncode();
 
-void
+int
 main(argc, argv)
 int argc;
 char *argv[];
