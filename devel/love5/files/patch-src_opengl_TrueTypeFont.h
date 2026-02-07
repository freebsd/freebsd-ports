--- src/opengl/TrueTypeFont.h.orig	2013-12-13 10:36:51.000000000 +0100
+++ src/opengl/TrueTypeFont.h	2013-12-13 10:38:20.000000000 +0100
@@ -13,10 +13,10 @@
 
 // FreeType2
 #include <ft2build.h>
-#include <freetype/freetype.h>
-#include <freetype/ftglyph.h>
-#include <freetype/ftoutln.h>
-#include <freetype/fttrigon.h>
+#include FT_FREETYPE_H
+#include FT_GLYPH_H
+#include FT_OUTLINE_H
+#include FT_TRIGONOMETRY_H
 
 // STD
 #include <string>
