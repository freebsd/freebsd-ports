--- test-ft-gtk.c.orig	Mon Mar 22 23:17:19 2004
+++ test-ft-gtk.c	Mon Mar 22 23:17:38 2004
@@ -34,7 +34,8 @@
 
 #include <gdk-pixbuf/gdk-pixbuf.h>
 
-#include <freetype/freetype.h>
+#include <ft2build.h>
+#include FT_FREETYPE_H
 
 #include <libart_lgpl/art_misc.h>
 #include <libart_lgpl/art_rect.h>
