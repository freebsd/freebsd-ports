--- src/appleseed/foundation/platform/thread.cpp.orig	2015-06-13 09:38:53 UTC
+++ src/appleseed/foundation/platform/thread.cpp
@@ -47,6 +47,9 @@
 // Platform headers.
 #if defined __APPLE__
 #include <pthread.h>
+#elif defined __FreeBSD__
+#include <pthread.h>
+#include <pthread_np.h>
 #elif defined __linux__
 #include <sys/prctl.h>
 #endif
@@ -325,6 +328,14 @@ namespace foundation
         pthread_setname_np(name);
     }
 
+// FreeBSD.
+#elif defined __FreeBSD__
+
+    void set_current_thread_name(const char* name)
+    {
+        pthread_set_name_np(pthread_self(), name);
+    }
+
 // Linux.
 #elif defined __linux__
 
