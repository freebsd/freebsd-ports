--- src/SDL_ttf.c.orig	Wed Oct 15 02:44:17 2003
+++ src/SDL_ttf.c	Thu Aug 12 15:06:42 2004
@@ -39,7 +39,8 @@
 #define FREEA(p) free(p)
 #endif
 
-#include <freetype/freetype.h>
+#include <ft2build.h>
+#include FT_FREETYPE_H
 #include <freetype/ftoutln.h>
 #include <freetype/ttnameid.h>
 #include <freetype/internal/ftobjs.h>
