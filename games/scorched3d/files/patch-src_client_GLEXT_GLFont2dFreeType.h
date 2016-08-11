--- src/client/GLEXT/GLFont2dFreeType.h.orig	2016-06-20 14:16:37 UTC
+++ src/client/GLEXT/GLFont2dFreeType.h
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
