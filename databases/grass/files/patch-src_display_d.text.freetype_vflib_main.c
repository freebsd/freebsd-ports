--- src/display/d.text.freetype/vflib/main.c.orig	Mon Mar 22 13:37:39 2004
+++ src/display/d.text.freetype/vflib/main.c	Mon Mar 22 13:37:50 2004
@@ -31,7 +31,8 @@
 #endif
 
 #ifndef	VFlib
-#include <freetype/freetype.h>
+#include <ft2build.h>
+#include FT_FREETYPE_H
 #else
 #include <VFlib-3_6.h>
 #endif
