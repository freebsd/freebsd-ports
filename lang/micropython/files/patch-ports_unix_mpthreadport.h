--- ports/unix/mpthreadport.h.orig	2026-05-18 08:33:30 UTC
+++ ports/unix/mpthreadport.h
@@ -25,9 +25,14 @@
  */
 
 #include <pthread.h>
+#include <semaphore.h>
 #include <stdbool.h>
 
-typedef pthread_mutex_t mp_thread_mutex_t;
+// Use POSIX semaphores for _thread.allocate_lock() so that cross-thread
+// unlock works correctly.  FreeBSD's default pthread mutex type is
+// ERRORCHECK, which rejects unlock by a non-owner thread (EPERM).
+// sem_t has no ownership concept: any thread may post or wait.
+typedef sem_t mp_thread_mutex_t;
 typedef pthread_mutex_t mp_thread_recursive_mutex_t;
 
 void mp_thread_init(void);
