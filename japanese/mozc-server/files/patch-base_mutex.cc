--- base/mutex.cc.orig	2013-04-21 03:48:45.170269862 +0900
+++ base/mutex.cc	2013-04-21 04:16:39.083269637 +0900
@@ -296,7 +296,7 @@
   // PTHREAD_MUTEX_RECURSIVE_NP but Mac OS X 10.5 does not
   pthread_mutexattr_t attr;
   pthread_mutexattr_init(&attr);
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(__FreeBSD__)
   pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
 #elif defined(OS_LINUX)
   pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE_NP);
