--- ./cliplibs/clip-gd/gd/gdft.c.orig	Mon Apr 19 22:33:22 2004
+++ ./cliplibs/clip-gd/gd/gdft.c	Mon Apr 19 23:04:04 2004
@@ -33,7 +33,8 @@
 #else
 
 #include "gdcache.h"
-#include "freetype/freetype.h"
+#include <ft2build.h>
+#include FT_FREETYPE_H
 #include "freetype/ftglyph.h"
 
 /* number of fonts cached before least recently used is replaced */
