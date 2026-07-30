--- src/preference.c.orig	2026-07-30 00:29:59 UTC
+++ src/preference.c
@@ -27,7 +27,7 @@
 #ifdef __WIN32__
 #include <pango/pangowin32.h>
 #else
-#include <pango/pangox.h>
+#include <pango/pangocairo.h>
 #endif
 
 #include "dictbar.h"
@@ -429,7 +429,7 @@ void  calculate_font_size(){
 		return;
 	}
 
-	fontmap = pango_x_font_map_for_display(display);
+	fontmap = pango_cairo_font_map_get_default();
 #endif
 
 	if(fontmap == NULL){
