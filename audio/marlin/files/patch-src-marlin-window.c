--- src/marlin-window.c.orig	Wed Jul 13 13:06:02 2005
+++ src/marlin-window.c	Wed Jul 13 17:50:41 2005
@@ -213,6 +213,7 @@
 void marlin_window_set_edit_name (MarlinWindow *window);
 void marlin_window_pause_sample (MarlinWindow *window);
 void marlin_window_save_sample_as (MarlinWindow *window);
+void marlin_window_repeat_sample (MarlinWindow *window);
 
 static GtkWindowClass *parent_class = NULL;
 static guint signals[LAST_SIGNAL];
