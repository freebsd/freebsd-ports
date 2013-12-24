--- src/drawGlyph.cpp.orig	2013-12-13 10:13:26.000000000 +0100
+++ src/drawGlyph.cpp	2013-12-13 10:15:19.000000000 +0100
@@ -6,7 +6,8 @@
  */
 
 #include <ostream>
-#include <freetype/ftoutln.h>
+#include <ft2build.h>
+#include FT_OUTLINE_H
 #include <algorithm>
 #include <LASi.h>
 #include <config.h>
