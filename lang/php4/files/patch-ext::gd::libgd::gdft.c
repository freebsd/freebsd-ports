--- ext/gd/libgd/gdft.c.orig	Thu Mar 18 16:41:43 2004
+++ ext/gd/libgd/gdft.c	Thu Mar 18 16:49:39 2004
@@ -60,8 +60,9 @@
 #else
 
 #include "gdcache.h"
-#include "freetype/freetype.h"
-#include "freetype/ftglyph.h"
+#include <ft2build.h>
+#include FT_FREETYPE_H
+#include FT_GLYPH_H
 
 /* number of fonts cached before least recently used is replaced */
 #define FONTCACHESIZE 6
