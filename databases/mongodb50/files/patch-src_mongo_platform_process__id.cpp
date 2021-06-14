--- src/mongo/platform/process_id.cpp.orig	2021-03-26 23:29:14 UTC
+++ src/mongo/platform/process_id.cpp
@@ -35,6 +35,10 @@
 #include <pthread.h>
 #endif
 
+#if defined(__FreeBSD__)
+#include <pthread_np.h>
+#endif
+
 #if defined(__linux__)
 #include <sys/syscall.h>
 #include <sys/types.h>
@@ -72,6 +76,10 @@ inline NativeProcessId getCurrentNativeThreadId() {
     uint64_t tid;
     invariant(::pthread_threadid_np(NULL, &tid) == 0);
     return tid;
+}
+#elif __FreeBSD__
+inline NativeProcessId getCurrentNativeThreadId() {
+    return pthread_getthreadid_np();
 }
 #else
 inline NativeProcessId getCurrentNativeThreadId() {
