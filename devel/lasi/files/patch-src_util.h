--- src/util.h.orig	2013-12-13 10:13:16.000000000 +0100
+++ src/util.h	2013-12-13 10:17:01.000000000 +0100
@@ -18,7 +18,7 @@
 
 #include <ft2build.h>
 #include FT_FREETYPE_H
-#include <freetype/ftglyph.h>
+#include FT_GLYPH_H
 
 std::ostream& operator<<(std::ostream&, const FT_Library);
 std::ostream& operator<<(std::ostream&, const FT_Face);
