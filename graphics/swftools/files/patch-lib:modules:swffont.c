--- lib/modules/swffont.c.orig	Mon Aug 16 11:32:50 2004
+++ lib/modules/swffont.c	Mon Aug 16 11:33:05 2004
@@ -32,6 +32,8 @@
 
 #ifdef HAVE_FREETYPE
 
+#include <ft2build.h>
+#include FT_FREETYPE_H
 #include <freetype/freetype.h>
 #include <freetype/ftglyph.h>
 #include <freetype/ftsizes.h>
