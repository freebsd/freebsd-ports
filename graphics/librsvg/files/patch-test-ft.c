--- test-ft.c.orig	Mon Mar 22 23:17:54 2004
+++ test-ft.c	Mon Mar 22 23:18:06 2004
@@ -30,7 +30,8 @@
 
 #include <gdk-pixbuf/gdk-pixbuf.h>
 
-#include <freetype/freetype.h>
+#include <ft2build.h>
+#include FT_FREETYPE_H
 
 #include <libart_lgpl/art_misc.h>
 #include <libart_lgpl/art_rect.h>
