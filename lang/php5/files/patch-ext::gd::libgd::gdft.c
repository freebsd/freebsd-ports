--- ext/gd/libgd/gdft.c.orig	Sun Dec 28 22:07:18 2003
+++ ext/gd/libgd/gdft.c	Thu Mar 18 16:54:09 2004
@@ -63,7 +63,7 @@
 #include "gdcache.h"
 #include <ft2build.h>
 #include FT_FREETYPE_H
-#include "freetype/ftglyph.h"
+#include FT_GLYPH_H
 
 /* number of fonts cached before least recently used is replaced */
 #define FONTCACHESIZE 6
