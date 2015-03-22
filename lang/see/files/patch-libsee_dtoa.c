--- libsee/dtoa.c.orig	2009-04-26 23:04:58.000000000 +0200
+++ libsee/dtoa.c	2015-03-16 15:46:21.218950229 +0100
@@ -252,6 +252,14 @@
 #include "math.h"
 #endif
 
+#include <pthread.h>
+
+static pthread_mutex_t dtoaLock[2] = { PTHREAD_MUTEX_INITIALIZER, PTHREAD_MUTEX_INITIALIZER };
+
+#define MULTIPLE_THREADS
+#define ACQUIRE_DTOA_LOCK(n) pthread_mutex_lock(&dtoaLock[n]);
+#define FREE_DTOA_LOCK(n) pthread_mutex_unlock(&dtoaLock[n]);
+
 #ifdef __cplusplus
 extern "C" {
 #endif
