--- src/modules/font/freetype/Font.h.orig	2013-12-13 10:24:12.000000000 +0100
+++ src/modules/font/freetype/Font.h	2013-12-13 10:25:51.000000000 +0100
@@ -30,10 +30,10 @@
 #else
 #include <ft2build.h>
 #endif
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
