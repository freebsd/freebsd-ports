--- vumeter.c.orig	2014-09-14 12:31:32 UTC
+++ vumeter.c
@@ -809,12 +809,8 @@ vumeter_draw_retro (w_vumeter_t *w, cair
 {
     if (!w->surf_png) {
         char path[PATH_MAX];
-        const char *home_dir = getenv ("HOME");
-        if (home_dir && strcmp(home_dir, "") == 0) {
-            home_dir = NULL;
-        }
-        const int sz = snprintf (path, PATH_MAX, "%s/vumeter.png", home_dir);
-        if (!home_dir || !path) {
+        if (snprintf (path, PATH_MAX, "%s/vumeter.png",
+          deadbeef->get_pixmap_dir()) < 0) {
             return;
         }
         w->surf_png = cairo_image_surface_create_from_png (path);
@@ -858,7 +854,7 @@ vumeter_draw_bars (w_vumeter_t *w, cairo
 
     unsigned char *data = cairo_image_surface_get_data (w->surf);
     if (!data) {
-        return FALSE;
+        return;
     }
     int stride = cairo_image_surface_get_stride (w->surf);
     memset (data, 0, height * stride);
