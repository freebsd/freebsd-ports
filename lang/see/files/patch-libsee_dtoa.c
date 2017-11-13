--- libsee/dtoa.c.orig	2009-04-26 21:04:58 UTC
+++ libsee/dtoa.c
@@ -252,6 +252,14 @@ static double private_mem[PRIVATE_mem], 
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
