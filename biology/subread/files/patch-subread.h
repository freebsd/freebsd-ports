--- subread.h.orig	2018-11-08 14:46:06 UTC
+++ subread.h
@@ -102,7 +102,7 @@
 
 #define USE_POSIX_MUTEX_LOCK
 
-#if defined(MACOS) || defined(FREEBSD) || defined(USE_POSIX_MUTEX_LOCK)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(USE_POSIX_MUTEX_LOCK)
 typedef pthread_mutex_t subread_lock_t;
 #define pthread_spinlock_t pthread_mutex_t
 #define pthread_spin_lock pthread_mutex_lock
