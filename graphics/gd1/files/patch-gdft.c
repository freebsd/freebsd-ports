--- gdft.c.orig	Sun Mar 21 18:25:37 2004
+++ gdft.c	Sun Mar 21 18:26:17 2004
@@ -33,7 +33,8 @@
 #else
 
 #include "gdcache.h"
-#include "freetype/freetype.h"
+#include "ft2build.h"
+#include  FT_FREETYPE_H
 #include "freetype/ftglyph.h"
 
 /* number of fonts cached before least recently used is replaced */
