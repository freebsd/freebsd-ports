--- threadutil/inc/ithread.h.orig	Wed Aug 16 15:52:47 2006
+++ threadutil/inc/ithread.h	Wed Aug 16 15:53:52 2006
@@ -47,6 +47,10 @@
  #include <unistd.h>
 #endif
 
+#ifdef __FreeBSD__
+#define PTHREAD_MUTEX_RECURSIVE_NP PTHREAD_MUTEX_RECURSIVE
+#endif
+
 #define ITHREAD_MUTEX_FAST_NP PTHREAD_MUTEX_FAST_NP
 #define ITHREAD_MUTEX_RECURSIVE_NP PTHREAD_MUTEX_RECURSIVE_NP
 #define ITHREAD_MUTEX_ERRORCHECK_NP PTHREAD_MUTEX_ERRORCHECK_NP
