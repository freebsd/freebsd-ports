--- gio/kqueue/kqueue-helper.h.orig	2018-04-09 22:47:22.070991000 +0200
+++ gio/kqueue/kqueue-helper.h	2018-04-09 22:47:44.329479000 +0200
@@ -23,16 +23,31 @@
 #ifndef __KQUEUE_HELPER_H
 #define __KQUEUE_HELPER_H
 
-#include "kqueue-sub.h"
 #include <gio/glocalfilemonitor.h>
 #include <gio/gfilemonitor.h>
 
-gboolean _kh_startup        (void);
-gboolean _kh_add_sub        (kqueue_sub *sub);
-gboolean _kh_cancel_sub     (kqueue_sub *sub);
+#include "dep-list.h"
 
-gboolean _kh_start_watching (kqueue_sub *sub);
+/**
+ * kqueue_sub:
+ * @filename: a name of the file to monitor
+ * @fd: the associated file descriptor (used by kqueue)
+ *
+ * Represents a subscription on a file or directory.
+ */
+typedef struct
+{
+  GLocalFileMonitor   *mon;
+  GFileMonitorSource  *source;
+  gchar*    filename;
+  int       fd;
+  dep_list* deps;
+  int       is_dir;
+} kqueue_sub;
 
-void     _kh_dir_diff       (kqueue_sub *sub, GFileMonitorSource *source);
+gboolean _kqsub_start_watching (kqueue_sub *sub);
+void _kh_dir_diff    (kqueue_sub *sub);
+void _km_add_missing (kqueue_sub *sub);
+void _km_remove      (kqueue_sub *sub);
 
 #endif /* __KQUEUE_HELPER_H */
