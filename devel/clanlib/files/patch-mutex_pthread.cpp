--- Sources/Core/System/Unix/mutex_pthread.cpp.orig	Sat Sep  6 05:33:06 2003
+++ Sources/Core/System/Unix/mutex_pthread.cpp	Mon Sep  8 05:08:56 2003
@@ -32,11 +32,7 @@
 // suck:
 extern "C"
 {
-#ifdef __FreeBSD__
-	int pthread_mutexattr_settype(pthread_mutexattr_t *attr, int kind);
-#else
 	int pthread_mutexattr_setkind_np(pthread_mutexattr_t *attr, int kind);
-#endif
 }
 
 CL_Mutex *CL_Mutex::create()
@@ -59,7 +55,7 @@
 #  define PTHREAD_MUTEX_RECURSIVE_NP
 #endif
 
-#ifdef PTHREAD_MUTEX_RECURSIVE_NP
+#ifndef PTHREAD_MUTEX_RECURSIVE_NP
 // FreeBSD & cygwin
 	pthread_mutexattr_setkind_np(&attr, PTHREAD_MUTEX_RECURSIVE);
 #else
