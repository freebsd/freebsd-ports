--- src/marlin-window.c.orig	Mon Jun 27 00:54:33 2005
+++ src/marlin-window.c	Wed Jul 13 00:44:04 2005
@@ -210,6 +210,8 @@
 void marlin_window_set_edit_name (MarlinWindow *window);
 void marlin_window_pause_sample (MarlinWindow *window);
 void marlin_window_save_sample_as (MarlinWindow *window);
+void set_marker_popup_sensitive (MarlinWindow *window, gboolean sensitive);
+void marlin_window_repeat_sample (MarlinWindow *window);
 
 static GtkWindowClass *parent_class = NULL;
 static guint signals[LAST_SIGNAL];
