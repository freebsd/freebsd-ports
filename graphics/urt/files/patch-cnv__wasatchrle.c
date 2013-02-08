--- cnv/wasatchrle.c.orig	1992-01-21 03:33:32.000000000 +0900
+++ cnv/wasatchrle.c	2012-10-16 00:57:04.000000000 +0900
@@ -28,6 +28,7 @@
  */
 
 #include <stdio.h>
+#include <string.h>
 #include <ctype.h>
 #include <errno.h>
 #include "rle.h"
@@ -51,7 +52,7 @@
     rle_pixel count, data;
 } was_op;
 
-void
+int
 main(argc, argv)
 int argc;
 char **argv;
