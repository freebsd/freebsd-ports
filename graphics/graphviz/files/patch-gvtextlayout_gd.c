--- plugin/gd/gvtextlayout_gd.c.orig	2007-07-20 14:38:03.000000000 -0400
+++ plugin/gd/gvtextlayout_gd.c	2007-09-12 13:20:12.000000000 -0400
@@ -26,7 +26,7 @@
 #ifdef HAVE_LIBGD
 #include "gd.h"
 
-#if defined(HAVE_LIBGD) && defined(HAVE_LIBFREETYPE) && defined(HAVE_GD_FREETYPE)
+#if defined(HAVE_LIBGD) && defined(HAVE_GD_FREETYPE)
 
 /* fontsize at which text is omitted entirely */
 #define FONTSIZE_MUCH_TOO_SMALL 0.15
@@ -172,7 +172,7 @@
 #endif
 
 gvplugin_installed_t gvtextlayout_gd_types[] = {
-#if defined(HAVE_LIBGD) && defined(HAVE_LIBFREETYPE) && defined(HAVE_GD_FREETYPE)
+#if defined(HAVE_LIBGD) && defined(HAVE_GD_FREETYPE)
     {0, "textlayout", 2, &gd_textlayout_engine, NULL},
 #endif
     {0, NULL, 0, NULL, NULL}
