--- logview/loglist.h.orig	Wed Apr 19 00:30:12 2006
+++ logview/loglist.h	Wed Apr 19 00:30:23 2006
@@ -39,6 +39,7 @@ typedef struct LogListClass
 	GtkTreeViewClass parent_class;
 }LogListClass;
 
+GType loglist_get_type (void);
 GtkWidget *loglist_new (void);
 void loglist_connect (LogList *list, LogviewWindow *window);
 void loglist_add_log (LogList *list, Log *log);
