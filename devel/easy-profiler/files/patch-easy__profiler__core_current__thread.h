--- easy_profiler_core/current_thread.h.orig	2021-06-09 13:16:22 UTC
+++ easy_profiler_core/current_thread.h
@@ -60,6 +60,10 @@ The Apache License, Version 2.0 (the "License");
 # include <sys/syscall.h>
 #endif
 
+#if defined(__DragonFly__) || defined(__FreeBSD__)
+#include <pthread_np.h>
+#endif
+
 inline profiler::thread_id_t getCurrentThreadId()
 {
 #ifdef _WIN32
@@ -76,6 +80,9 @@ inline profiler::thread_id_t getCurrentThreadId()
 #   endif
 #elif defined(__QNX__)
     EASY_THREAD_LOCAL static const profiler::thread_id_t _id = (profiler::thread_id_t)gettid();
+    return _id;
+#elif defined(__DragonFly__) || defined(__FreeBSD__)
+    EASY_THREAD_LOCAL static const profiler::thread_id_t _id = (profiler::thread_id_t)pthread_getthreadid_np();
     return _id;
 #else
     EASY_THREAD_LOCAL static const profiler::thread_id_t _id = (profiler::thread_id_t)syscall(__NR_gettid);
