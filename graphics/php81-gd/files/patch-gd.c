--- gd.c.orig	2020-09-29 22:36:51 UTC
+++ gd.c
@@ -72,7 +72,7 @@ static int le_gd_font;
 # include FT_FREETYPE_H
 #endif
 
-#if defined(HAVE_GD_XPM) && defined(HAVE_GD_BUNDLED)
+#if defined(HAVE_XPM) && defined(HAVE_GD_XPM) && defined(HAVE_GD_BUNDLED)
 # include "X11/xpm.h"
 #endif
 
