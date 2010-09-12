--- Python/thread_pthread.h.orig	2010-05-09 22:46:46.000000000 +0800
+++ Python/thread_pthread.h	2010-08-15 14:27:51.886823397 +0800
@@ -26,13 +26,18 @@
 #endif
 #endif
 
+#ifdef __FreeBSD__
+#include <osreldate.h>
+#endif
+
 /* The POSIX spec says that implementations supporting the sem_*
    family of functions must indicate this by defining
    _POSIX_SEMAPHORES. */
 #ifdef _POSIX_SEMAPHORES
 /* On FreeBSD 4.x, _POSIX_SEMAPHORES is defined empty, so
    we need to add 0 to make it work there as well. */
-#if (_POSIX_SEMAPHORES+0) == -1
+#if defined(__FreeBSD__) && __FreeBSD_version < 701104 && \
+    (_POSIX_SEMAPHORES+0) == -1
 #define HAVE_BROKEN_POSIX_SEMAPHORES
 #else
 #include <semaphore.h>
@@ -44,7 +49,6 @@
    in default setting.  So the process scope is preferred to get
    enough number of threads to work. */
 #ifdef __FreeBSD__
-#include <osreldate.h>
 #if __FreeBSD_version >= 500000 && __FreeBSD_version < 504101
 #undef PTHREAD_SYSTEM_SCHED_SUPPORTED
 #endif
@@ -149,6 +153,7 @@
 {
     pthread_t th;
     int status;
+    sigset_t set, oset;
 #if defined(THREAD_STACK_SIZE) || defined(PTHREAD_SYSTEM_SCHED_SUPPORTED)
     pthread_attr_t attrs;
 #endif
@@ -177,6 +182,8 @@
 #if defined(PTHREAD_SYSTEM_SCHED_SUPPORTED)
     pthread_attr_setscope(&attrs, PTHREAD_SCOPE_SYSTEM);
 #endif
+    sigfillset(&set);
+    SET_THREAD_SIGMASK(SIG_BLOCK, &set, &oset);
 
     status = pthread_create(&th,
 #if defined(THREAD_STACK_SIZE) || defined(PTHREAD_SYSTEM_SCHED_SUPPORTED)
@@ -188,6 +195,7 @@
                              (void *)arg
                              );
 
+    SET_THREAD_SIGMASK(SIG_SETMASK, &oset, NULL);
 #if defined(THREAD_STACK_SIZE) || defined(PTHREAD_SYSTEM_SCHED_SUPPORTED)
     pthread_attr_destroy(&attrs);
 #endif
