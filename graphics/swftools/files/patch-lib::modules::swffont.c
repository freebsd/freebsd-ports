--- lib/modules/swffont.c.orig	Sat Aug 14 16:19:02 2004
+++ lib/modules/swffont.c	Sun Aug 15 02:16:02 2004
@@ -32,7 +32,8 @@
 
 #ifdef HAVE_FREETYPE
 
-#include <freetype/freetype.h>
+#include <ft2build.h>
+#include FT_FREETYPE_H
 #include <freetype/ftglyph.h>
 #include <freetype/ftsizes.h>
 #include <freetype/ftsnames.h>
