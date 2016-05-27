--- src/app/util/freetype_utils.cpp.orig	2015-11-06 13:40:13 UTC
+++ src/app/util/freetype_utils.cpp
@@ -21,7 +21,7 @@
 
 #include <stdexcept>
 
-#include "freetype/ftglyph.h"
+#include <ftglyph.h>
 #include "ft2build.h"
 #include FT_FREETYPE_H
 
