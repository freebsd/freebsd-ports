--- src/glyphMgr.cpp.orig	2013-12-13 10:13:39.000000000 +0100
+++ src/glyphMgr.cpp	2013-12-13 10:17:39.000000000 +0100
@@ -10,8 +10,7 @@
 
 #include <ft2build.h>
 #include FT_FREETYPE_H
-
-#include <freetype/ftglyph.h>
+#include FT_GLYPH_H
 
 #include <cassert>
 #include "util.h"
