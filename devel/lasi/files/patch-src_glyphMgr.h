--- src/glyphMgr.h.orig	2013-12-13 10:13:45.000000000 +0100
+++ src/glyphMgr.h	2013-12-13 10:17:50.000000000 +0100
@@ -15,8 +15,7 @@
 
 #include <ft2build.h>
 #include FT_FREETYPE_H
-
-#include <freetype/ftglyph.h>
+#include FT_GLYPH_H
 
 /** Manage FT_Glyph by insuring that FT_Glyph is handled correctly.
  */
