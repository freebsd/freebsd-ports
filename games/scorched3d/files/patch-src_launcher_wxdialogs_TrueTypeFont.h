--- src/launcher/wxdialogs/TrueTypeFont.h.orig	2013-12-17 10:01:02.000000000 +0100
+++ src/launcher/wxdialogs/TrueTypeFont.h	2013-12-17 10:01:16.000000000 +0100
@@ -25,10 +25,10 @@
 #include <wx/image.h>
 #include <ft2build.h>
 #include <string>
-#include <freetype/freetype.h>
-#include <freetype/ftglyph.h>
-#include <freetype/ftoutln.h>
-#include <freetype/fttrigon.h>
+#include FT_FREETYPE_H
+#include FT_GLYPH_H
+#include FT_OUTLINE_H
+#include FT_TRIGONOMETRY_H
 
 class TrueTypeFont
 {
