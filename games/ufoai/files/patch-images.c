--- src/shared/images.c.orig	2010-11-29 17:46:35.000000000 +0100
+++ src/shared/images.c	2012-04-25 06:15:32.000000000 +0200
@@ -32,6 +32,7 @@
 
 #include <jpeglib.h>
 #include <png.h>
+#include <zlib.h>
 
 /** image formats, tried in this order */
 static char *IMAGE_TYPES[] = { "tga", "png", "jpg", NULL };
