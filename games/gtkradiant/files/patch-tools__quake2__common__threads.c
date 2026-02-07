--- ./tools/quake2/common/threads.c.orig	Thu Mar 16 16:09:46 2006
+++ ./tools/quake2/common/threads.c	Thu Mar 16 16:21:27 2006
@@ -542,11 +542,7 @@
 
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
 
