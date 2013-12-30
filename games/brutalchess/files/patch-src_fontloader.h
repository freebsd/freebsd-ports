--- src/fontloader.h.orig	2013-12-13 10:49:49.000000000 +0100
+++ src/fontloader.h	2013-12-13 10:50:39.000000000 +0100
@@ -12,11 +12,9 @@
 //FreeType Headers
 #include <ft2build.h>
 #include FT_FREETYPE_H
-
-#include <freetype/freetype.h>
-#include <freetype/ftglyph.h>
-#include <freetype/ftoutln.h>
-#include <freetype/fttrigon.h>
+#include FT_GLYPH_H
+#include FT_OUTLINE_H
+#include FT_TRIGONOMETRY_H
 
 // Other Headers we'll need.
 #include <vector>
