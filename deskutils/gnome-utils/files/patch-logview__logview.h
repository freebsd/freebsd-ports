--- logview/logview.h.orig	Wed Apr 19 12:39:07 2006
+++ logview/logview.h	Wed Apr 19 12:40:08 2006
@@ -73,6 +73,7 @@
 void logview_set_window_title (LogviewWindow *window);
 void logview_set_font (LogviewWindow *window, const gchar *fontname);
 void logview_show_main_content (LogviewWindow *window);
+GType logview_window_get_type (void);
 GtkWidget *logview_window_new (void);
 
 #endif /* __LOGVIEW_H__ */
