--- plugins/image_filter/text/if_text.cpp.orig	Mon Mar 22 23:23:31 2004
+++ plugins/image_filter/text/if_text.cpp	Mon Mar 22 23:23:43 2004
@@ -18,7 +18,8 @@
 
 #include <cmath>
 #include <string.h>
-#include <freetype/freetype.h>
+#include <ft2build.h>
+#include FT_FREETYPE_H
 #include "llapi/file.h"
 #include "llapi/scene.h"
 #include "if_text.h"
