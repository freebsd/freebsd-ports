--- Sources/TTF/font_ttf.cpp.orig	Mon Mar 22 13:45:53 2004
+++ Sources/TTF/font_ttf.cpp	Mon Mar 22 13:46:10 2004
@@ -21,7 +21,8 @@
 #include <stdlib.h>
 #include "Display/Font/font_generic.h"
 
-#include <freetype/freetype.h>
+#include <ft2build.h>
+#include FT_FREETYPE_H
 
 #include "font_ttf.h"
 
