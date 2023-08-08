--- gd.c.orig	2023-06-06 15:54:29 UTC
+++ gd.c
@@ -80,7 +80,7 @@
 # include FT_FREETYPE_H
 #endif
 
-#if defined(HAVE_GD_XPM) && defined(HAVE_GD_BUNDLED)
+#if defined(HAVE_XPM) && defined(HAVE_GD_XPM) && defined(HAVE_GD_BUNDLED)
 # include "X11/xpm.h"
 #endif
 
