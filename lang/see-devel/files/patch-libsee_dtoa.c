--- libsee/dtoa.c.orig	2005-12-24 04:35:38.000000000 +0100
+++ libsee/dtoa.c	2008-04-07 11:30:11.529829910 +0200
@@ -168,6 +168,11 @@
  *	the result overflows to +-Infinity or underflows to 0.
  */
 
+#ifdef MULTIPLE_THREADS
+#include <pthread.h>
+static pthread_mutex_t mylock[2] = { PTHREAD_MUTEX_INITIALIZER, PTHREAD_MUTEX_INITIALIZER };
+#endif
+
 #ifndef Long
 #define Long long
 #endif
@@ -470,6 +475,9 @@
 #ifndef MULTIPLE_THREADS
 #define ACQUIRE_DTOA_LOCK(n)	/*nothing*/
 #define FREE_DTOA_LOCK(n)	/*nothing*/
+#else
+#define ACQUIRE_DTOA_LOCK(n)	pthread_mutex_lock(&mylock[n]);
+#define FREE_DTOA_LOCK(n)	pthread_mutex_unlock(&mylock[n]);
 #endif
 
 #define Kmax 15
