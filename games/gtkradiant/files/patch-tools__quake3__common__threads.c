--- ./tools/quake3/common/threads.c.orig	Fri Feb 10 19:01:20 2006
+++ ./tools/quake3/common/threads.c	Thu Mar 16 16:36:04 2006
@@ -415,7 +415,7 @@
 =======================================================================
 */
 
-#ifdef __linux__
+#if defined (__linux__) || defined (__APPLE__) || defined (__FreeBSD__)
 #define USED
 
 int numthreads = 4;
@@ -540,11 +540,7 @@
 
     if(pthread_mutexattr_init(&mattrib) != 0)
       Error("pthread_mutexattr_init failed");
-#if __GLIBC_MINOR__ == 1
-    if (pthread_mutexattr_settype(&mattrib, PTHREAD_MUTEX_FAST_NP) != 0)
-#else
-    if (pthread_mutexattr_settype(&mattrib, PTHREAD_MUTEX_ADAPTIVE_NP) != 0)
-#endif
+    if (pthread_mutexattr_settype(&mattrib, PTHREAD_MUTEX_NORMAL) != 0)
       Error ("pthread_mutexattr_settype failed");
     recursive_mutex_init(mattrib);
 
