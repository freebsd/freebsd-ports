--- include_freetype.h.orig	2013-12-24 20:30:39.000000000 +0100
+++ include_freetype.h	2013-12-24 20:31:30.000000000 +0100
@@ -21,8 +21,7 @@
 
 #include <ft2build.h>
 #include FT_FREETYPE_H // this is not do-able in Pyrex
-#include <freetype/freetype.h>
-#include <freetype/ftoutln.h>
-#include <freetype/ftimage.h>
-#include <freetype/ftglyph.h>
+#include FT_OUTLINE_H
+#include FT_IMAGE_H
+#include FT_GLYPH_H
 
