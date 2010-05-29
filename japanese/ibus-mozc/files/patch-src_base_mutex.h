--- src/base/mutex.h.org	2010-05-29 11:06:10.678543934 +0900
+++ src/base/mutex.h	2010-05-29 11:25:17.454000870 +0900
@@ -87,7 +87,7 @@
 #endif
 
 #ifdef OS_LINUX
-#define PTHREAD_MUTEX_RECURSIVE_VALUE PTHREAD_MUTEX_RECURSIVE_NP
+#define PTHREAD_MUTEX_RECURSIVE_VALUE PTHREAD_MUTEX_RECURSIVE
 #endif
 
     pthread_mutexattr_t attr;
