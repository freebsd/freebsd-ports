--- SDL_ttf.c.orig	Thu Mar 18 15:06:45 2004
+++ SDL_ttf.c	Thu Mar 18 15:07:13 2004
@@ -39,7 +39,8 @@
 #define FREEA(p) free(p)
 #endif
 
-#include <freetype/freetype.h>
+#include <ft2build.h>
+#include FT_FREETYPE_H
 #include <freetype/ftoutln.h>
 #include <freetype/ttnameid.h>
 #include <freetype/internal/ftobjs.h>
