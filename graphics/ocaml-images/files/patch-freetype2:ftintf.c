--- freetype2/ftintf.c.orig	Wed Mar 24 10:51:28 2004
+++ freetype2/ftintf.c	Wed Mar 24 10:51:56 2004
@@ -20,7 +20,8 @@
 
 #if (HAVE_FREETYPE && HAVE_FREETYPE2)
 
-#include <freetype/freetype.h>
+#include <ft2build.h>
+#include FT_FREETYPE_H
 
 value init_FreeType()
 {
