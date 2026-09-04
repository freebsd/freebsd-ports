--- deps/LibMR/src/utils/thpool.c.orig	2025-04-15 11:24:04 UTC
+++ deps/LibMR/src/utils/thpool.c
@@ -19,6 +19,8 @@
 #include <time.h>
 #if defined(__linux__)
 #include <sys/prctl.h>
+#elif defined(__FreeBSD__)
+#include <pthread_np.h>
 #endif

 #include "thpool.h"
@@ -322,6 +324,8 @@ static void* thread_do(struct mr_thread* thread_p) {
   prctl(PR_SET_NAME, thread_name);
 #elif defined(__APPLE__) && defined(__MACH__)
   pthread_setname_np(thread_name);
+#elif defined(__FreeBSD__)
+  pthread_set_name_np(pthread_self(), thread_name);
 #else
   err("thread_do(): pthread_setname_np is not supported on this system");
 #endif
