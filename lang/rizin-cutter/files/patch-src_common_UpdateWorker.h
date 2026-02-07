--- src/common/UpdateWorker.h.orig	2024-03-28 17:50:45 UTC
+++ src/common/UpdateWorker.h
@@ -3,11 +3,8 @@
 
 #include <QtGlobal>
 
-#if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
-#    define CUTTER_UPDATE_WORKER_AVAILABLE 1
-#else
-#    define CUTTER_UPDATE_WORKER_AVAILABLE 0
-#endif
+// FreeBSD: Forcively disable update worker
+#define CUTTER_UPDATE_WORKER_AVAILABLE 0
 
 #if CUTTER_UPDATE_WORKER_AVAILABLE
 #    include <QDir>
