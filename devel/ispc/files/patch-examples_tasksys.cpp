--- examples/tasksys.cpp.orig	2016-07-08 11:13:52 UTC
+++ examples/tasksys.cpp
@@ -90,6 +90,8 @@
       #define ISPC_USE_CONCRT
     #elif defined(__linux__)
     #define ISPC_USE_PTHREADS
+    #elif defined(__FreeBSD__)
+    #define ISPC_USE_TBB_TASK_GROUP // ISPC_USE_PTHREADS fails for some reason, need to investigate
     #elif defined(__APPLE__)
       #define ISPC_USE_GCD
     #endif
