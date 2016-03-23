--- vumeter.c.orig	2014-09-14 12:31:32 UTC
+++ vumeter.c
@@ -386,6 +386,8 @@ on_config_changed (gpointer user_data, u
     return 0;
 }
 
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
 static void
 on_button_config (GtkMenuItem *menuitem, gpointer user_data)
 {
@@ -433,8 +435,6 @@ on_button_config (GtkMenuItem *menuitem,
     GtkWidget *applybutton1;
     GtkWidget *cancelbutton1;
     GtkWidget *okbutton1;
-#pragma GCC diagnostic push
-#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
     vumeter_properties = gtk_dialog_new ();
     gtk_window_set_title (GTK_WINDOW (vumeter_properties), "vumeter Properties");
     gtk_window_set_type_hint (GTK_WINDOW (vumeter_properties), GDK_WINDOW_TYPE_HINT_DIALOG);
@@ -753,9 +753,9 @@ on_button_config (GtkMenuItem *menuitem,
         break;
     }
     gtk_widget_destroy (vumeter_properties);
-#pragma GCC diagnostic pop
     return;
 }
+#pragma GCC diagnostic pop
 
 ///// vumeter vis
 void
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
