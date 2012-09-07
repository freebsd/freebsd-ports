--- base/mutex.cc.orig	2012-09-07 10:21:29.105022147 +0900
+++ base/mutex.cc	2012-09-07 11:37:36.899021514 +0900
@@ -296,7 +296,7 @@
   // PTHREAD_MUTEX_RECURSIVE_NP but Mac OS X 10.5 does not
   pthread_mutexattr_t attr;
   pthread_mutexattr_init(&attr);
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(__FreeBSD__)
   pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
 #elif defined(OS_LINUX)
   pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE_NP);
