--- ports/unix/mpthreadport.c.orig	2026-05-18 08:33:30 UTC
+++ ports/unix/mpthreadport.c
@@ -325,30 +325,30 @@ void mp_thread_mutex_init(mp_thread_mutex_t *mutex) {
 }
 
 void mp_thread_mutex_init(mp_thread_mutex_t *mutex) {
-    pthread_mutex_init(mutex, NULL);
+    // Initial value 1 = unlocked (semaphore counts available slots).
+    sem_init(mutex, 0, 1);
 }
 
 int mp_thread_mutex_lock(mp_thread_mutex_t *mutex, int wait) {
-    int ret;
     if (wait) {
-        ret = pthread_mutex_lock(mutex);
-        if (ret == 0) {
-            return 1;
-        }
+        int ret;
+        // sem_wait returns EINTR when a signal interrupts it (e.g. the GC
+        // signal sent to scan thread stacks).  Retry so we preserve the
+        // "block until acquired" semantics of the original pthread_mutex_lock.
+        do {
+            ret = sem_wait(mutex);
+        } while (ret != 0 && errno == EINTR);
+        return ret == 0 ? 1 : -errno;
     } else {
-        ret = pthread_mutex_trylock(mutex);
-        if (ret == 0) {
+        if (sem_trywait(mutex) == 0) {
             return 1;
-        } else if (ret == EBUSY) {
-            return 0;
         }
+        return errno == EAGAIN ? 0 : -errno;
     }
-    return -ret;
 }
 
 void mp_thread_mutex_unlock(mp_thread_mutex_t *mutex) {
-    pthread_mutex_unlock(mutex);
-    // TODO check return value
+    sem_post(mutex);
 }
 
 #if MICROPY_PY_THREAD_RECURSIVE_MUTEX
@@ -362,11 +362,20 @@ int mp_thread_recursive_mutex_lock(mp_thread_recursive
 }
 
 int mp_thread_recursive_mutex_lock(mp_thread_recursive_mutex_t *mutex, int wait) {
-    return mp_thread_mutex_lock(mutex, wait);
+    int ret;
+    if (wait) {
+        ret = pthread_mutex_lock(mutex);
+    } else {
+        ret = pthread_mutex_trylock(mutex);
+        if (ret == EBUSY) {
+            return 0;
+        }
+    }
+    return ret == 0 ? 1 : -ret;
 }
 
 void mp_thread_recursive_mutex_unlock(mp_thread_recursive_mutex_t *mutex) {
-    mp_thread_mutex_unlock(mutex);
+    pthread_mutex_unlock(mutex);
 }
 
 #endif // MICROPY_PY_THREAD_RECURSIVE_MUTEX
