--- jrd/isc_sync.c.orig	Tue Mar  5 21:11:25 2002
+++ jrd/isc_sync.c	Sat Jul  6 18:06:30 2002
@@ -1467,7 +1467,7 @@
     pthread_mutex_init (event->event_mutex, pthread_mutexattr_default);
     pthread_cond_init (event->event_semnum, pthread_condattr_default);
 #else
-#if (defined linux || defined DARWIN)
+#if (defined linux || defined DARWIN || defined FREEBSD)
     pthread_mutex_init (event->event_mutex, NULL);
     pthread_cond_init (event->event_semnum, NULL);
 #else
@@ -1596,7 +1596,7 @@
 #ifdef HP10
     if (micro_seconds > 0 && (ret == -1) && (errno == EAGAIN))
 #else
-#if (defined linux || defined DARWIN)
+#if (defined linux || defined DARWIN || defined FREEBSD)
     if (micro_seconds > 0 && (ret == ETIMEDOUT))
 #else
     if (micro_seconds > 0 && (ret == ETIME))
@@ -5198,7 +5198,7 @@
  **************************************/
 int	state;
 
-#if (!defined HP10 && !defined linux && !defined DARWIN)
+#if (!defined HP10 && !defined linux && !defined DARWIN && !defined FREEBSD)
 
 pthread_mutexattr_t     mattr;
 
@@ -5218,7 +5218,7 @@
 	 server (until we are to implement local IPC using shared
 	 memory in which case we need interprocess thread sync.
 */
-#if (defined linux || defined DARWIN)
+#if (defined linux || defined DARWIN || defined FREEBSD)
 return pthread_mutex_init (mutex->mtx_mutex, NULL);
 #else
 state = pthread_mutex_init (mutex->mtx_mutex, pthread_mutexattr_default);
