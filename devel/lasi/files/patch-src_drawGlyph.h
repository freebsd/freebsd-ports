--- src/drawGlyph.h.orig	2013-12-13 10:13:05.000000000 +0100
+++ src/drawGlyph.h	2013-12-13 10:15:40.000000000 +0100
@@ -10,7 +10,8 @@
 
 #include <iostream>
 #include <pango/pango.h>
-#include <freetype/freetype.h>
+#include <ft2build.h>
+#include FT_FREETYPE_H
 
 /** Generate the Postscript commands to draw the glyph
   * using the font in pPangoCtx.
