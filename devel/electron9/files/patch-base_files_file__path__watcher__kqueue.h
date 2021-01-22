--- base/files/file_path_watcher_kqueue.h.orig	2020-05-26 07:48:14 UTC
+++ base/files/file_path_watcher_kqueue.h
@@ -5,6 +5,10 @@
 #ifndef BASE_FILES_FILE_PATH_WATCHER_KQUEUE_H_
 #define BASE_FILES_FILE_PATH_WATCHER_KQUEUE_H_
 
+#ifdef __FreeBSD__
+#include <sys/stdint.h>
+#include <sys/types.h>
+#endif
 #include <sys/event.h>
 
 #include <memory>
