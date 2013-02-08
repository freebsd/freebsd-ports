--- tools/rlecomp.c.orig	1992-07-15 05:33:31.000000000 +0900
+++ tools/rlecomp.c	2012-10-15 22:52:09.000000000 +0900
@@ -30,6 +30,7 @@
  */
 
 #include <stdio.h>
+#include <string.h>
 #include "rle.h"
 #include "rle_raw.h"
 
@@ -63,7 +64,7 @@
 int * Anraw, *Bnraw;
 rle_pixel * non_zero_pixels;
 
-void
+int
 main(argc, argv)
 int	argc;
 char	*argv[];
