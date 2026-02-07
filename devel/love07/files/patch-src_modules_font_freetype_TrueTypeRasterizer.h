--- src/modules/font/freetype/TrueTypeRasterizer.h.orig	2013-12-13 10:24:01.000000000 +0100
+++ src/modules/font/freetype/TrueTypeRasterizer.h	2013-12-13 10:26:35.000000000 +0100
@@ -27,10 +27,10 @@
 
 // TrueType2
 #include <ft2build.h>
-#include <freetype/freetype.h>
-#include <freetype/ftglyph.h>
-#include <freetype/ftoutln.h>
-#include <freetype/fttrigon.h>
+#include FT_FREETYPE_H
+#include FT_GLYPH_H
+#include FT_OUTLINE_H
+#include FT_TRIGONOMETRY_H
 
 namespace love
 {
