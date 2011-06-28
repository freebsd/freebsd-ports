--- base/mutex.h.org	2010-11-06 10:44:01.433194789 +0900
+++ base/mutex.h	2010-11-06 10:44:28.939186472 +0900
@@ -82,11 +82,11 @@
     // PTHREAD_MUTEX_RECURSIVE_NP and PTHREAD_MUTEX_RECURSIVE seem to be
     // variants.  For example, Mac OS X 10.4 had
     // PTHREAD_MUTEX_RECURSIVE_NP but Mac OS X 10.5 does not
-#ifdef OS_MACOSX
+#if defined(OS_MACOSX) || defined(__FreeBSD__)
 #define PTHREAD_MUTEX_RECURSIVE_VALUE PTHREAD_MUTEX_RECURSIVE
 #endif
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX) && !defined(__FreeBSD__)
 #define PTHREAD_MUTEX_RECURSIVE_VALUE PTHREAD_MUTEX_RECURSIVE_NP
 #endif
 
