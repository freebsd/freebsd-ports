--- src/server/qgsfcgiserverresponse.cpp.orig	2025-04-18 12:00:43 UTC
+++ src/server/qgsfcgiserverresponse.cpp
@@ -31,6 +31,7 @@
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <chrono>
+#include <pthread_np.h>
 
 //
 // QgsFCGXStreamData copied from libfcgi FCGX_Stream_Data
@@ -114,7 +115,12 @@ void QgsSocketMonitoringThread::run()
   }
 
 #if defined( Q_OS_UNIX ) && !defined( Q_OS_ANDROID )
-  const pid_t threadId = gettid();
+  // https://github.com/qgis/QGIS/commit/6ecc1c31c95894199b88b56f8023e74807743957
+  #if !defined (__FreeBSD__)
+    const pid_t threadId = gettid();
+  #else
+    const pid_t threadId = pthread_getthreadid_np();
+  #endif
 
   char c;
 
