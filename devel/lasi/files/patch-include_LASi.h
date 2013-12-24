--- include/LASi.h.orig	2013-12-13 10:12:32.000000000 +0100
+++ include/LASi.h	2013-12-13 10:14:20.000000000 +0100
@@ -11,7 +11,8 @@
 #include <sstream>
 #include <map>
 #include <pango/pango.h>
-#include <freetype/ftglyph.h>
+#include <ft2build.h>
+#include FT_GLYPH_H
 
 class FreetypeGlyphMgr;
 class ContextMgr;
