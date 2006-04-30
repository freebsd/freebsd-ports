--- logview/logview-findbar.h.orig	Wed Apr 19 00:27:03 2006
+++ logview/logview-findbar.h	Wed Apr 19 00:27:17 2006
@@ -44,6 +44,7 @@ typedef struct LogviewFindBarClass
 	GtkHBoxClass parent_class;
 }LogviewFindBarClass;
 
+GType logview_findbar_get_type (void);
 GtkWidget *logview_findbar_new (void);
 void logview_findbar_connect (LogviewFindBar *findbar, LogviewWindow *logview);
 void logview_findbar_update_visibility (LogviewFindBar *findbar, LogviewWindow *logview);
