--- src/display/d.text.freetype/main.c.orig	Mon Mar 22 13:36:09 2004
+++ src/display/d.text.freetype/main.c	Mon Mar 22 13:36:46 2004
@@ -28,7 +28,8 @@
 #ifdef HAVE_ICONV_H
 #include <iconv.h>
 #endif
-#include <freetype/freetype.h>
+#include <ft2build.h>
+#include FT_FREETYPE_H
 #include "gis.h"
 #include "display.h"
 #include "raster.h"
