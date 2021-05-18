- bugfix patch from the upstream

--- app/gui-subs.h.orig	2021-05-18 18:36:26 UTC
+++ app/gui-subs.h
@@ -151,7 +151,7 @@ gui_subs_create_slider(const gchar* title,
     GtkAdjustment** adj,
     gboolean in_mainwindow)
 {
-    return gui_subs_create_slider(title, min, max, changedfunc, adj, in_mainwindow);
+    return gui_subs_create_slider_full(title, min, max, changedfunc, adj, in_mainwindow, NULL);
 }
 
 GtkWidget* gui_combo_new(GtkListStore* ls);
