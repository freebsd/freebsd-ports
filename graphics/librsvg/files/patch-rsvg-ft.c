--- rsvg-ft.c.orig	Mon Mar 22 23:16:39 2004
+++ rsvg-ft.c	Mon Mar 22 23:16:57 2004
@@ -28,7 +28,8 @@
 #include <stdlib.h>
 #include <math.h>
 
-#include <freetype/freetype.h>
+#include <ft2build.h>
+#include FT_FREETYPE_H
 
 #include <libart_lgpl/art_misc.h>
 #include <libart_lgpl/art_rect.h>
