--- examples/tasksys.cpp.orig	2019-04-20 16:09:47 UTC
+++ examples/tasksys.cpp
@@ -88,6 +88,8 @@
 #define ISPC_USE_CONCRT
 #elif defined(__linux__)
 #define ISPC_USE_PTHREADS
+#elif defined(__FreeBSD__)
+#define ISPC_USE_TBB_TASK_GROUP // ISPC_USE_PTHREADS fails for some reason, need to investigate
 #elif defined(__APPLE__)
 #define ISPC_USE_GCD
 #endif
@@ -101,6 +103,8 @@
 #define ISPC_IS_WINDOWS
 #elif defined(__linux__)
 #define ISPC_IS_LINUX
+#elif defined(__FreeBSD__)
+#define ISPC_IS_FREEBSD
 #elif defined(__APPLE__)
 #define ISPC_IS_APPLE
 #endif
