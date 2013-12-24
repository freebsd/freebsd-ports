--- src/client/GLEXT/GLFont2dFreeType.h.orig	2013-12-17 09:58:11.000000000 +0100
+++ src/client/GLEXT/GLFont2dFreeType.h	2013-12-17 09:59:18.000000000 +0100
@@ -23,10 +23,10 @@
 
 #include <GLEXT/GLFont2dStorage.h>
 #include <ft2build.h>
-#include <freetype/freetype.h>
-#include <freetype/ftglyph.h>
-#include <freetype/ftoutln.h>
-#include <freetype/fttrigon.h>
+#include FT_FREETYPE_H
+#include FT_GLYPH_H
+#include FT_OUTLINE_H
+#include FT_TRIGONOMETRY_H
 #include <string>
 
 class GLFont2dFreeType
