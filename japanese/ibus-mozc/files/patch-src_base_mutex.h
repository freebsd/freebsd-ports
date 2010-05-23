--- src/base/mutex.h.org	2010-05-23 14:03:03.131499800 +0900
+++ src/base/mutex.h	2010-05-23 13:58:38.728786327 +0900
@@ -87,7 +87,7 @@
 #endif
 
 #ifdef OS_LINUX
-#define PTHREAD_MUTEX_RECURSIVE_VALUE PTHREAD_MUTEX_RECURSIVE_NP
+#define PTHREAD_MUTEX_RECURSIVE_VALUE PTHREAD_MUTEX_RECURSIVE
 #endif
 
     pthread_mutexattr_t attr;
