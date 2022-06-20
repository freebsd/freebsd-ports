--- profiler_gui/thread_pool.cpp.orig	2022-06-20 05:17:12 UTC
+++ profiler_gui/thread_pool.cpp
@@ -73,7 +73,7 @@ static void setLowestThreadPriority()
 {
 #ifdef _WIN32
     SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_LOWEST);
-#elif !defined(__APPLE__)
+#elif !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__DragonFly__)
     pthread_attr_t attr;
     if (pthread_attr_init(&attr) == 0)
     {
