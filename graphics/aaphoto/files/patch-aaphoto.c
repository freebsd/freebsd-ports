--- aaphoto.c.orig	2011-01-26 16:39:58.000000000 +0100
+++ aaphoto.c	2012-04-23 19:07:00.000000000 +0200
@@ -243,6 +243,7 @@
 #ifndef __BMP_ONLY__
 #include <jasper/jasper.h>
 #include <png.h>
+#include <zlib.h>
 #include <jpeglib.h>
 #endif
 
