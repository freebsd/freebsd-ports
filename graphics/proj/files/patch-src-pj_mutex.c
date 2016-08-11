--- src/pj_mutex.c.orig	2015-09-10 13:41:24 UTC
+++ src/pj_mutex.c
@@ -122,11 +122,7 @@ void pj_acquire_lock()
         pthread_mutex_lock( &pj_precreated_lock);
 
         pthread_mutexattr_init(&mutex_attr);
-#ifdef HAVE_PTHREAD_MUTEX_RECURSIVE
         pthread_mutexattr_settype(&mutex_attr, PTHREAD_MUTEX_RECURSIVE);
-#else
-        pthread_mutexattr_settype(&mutex_attr, PTHREAD_MUTEX_RECURSIVE_NP);
-#endif
         pthread_mutex_init(&pj_core_lock, &mutex_attr);
         pj_core_lock_created = 1;
 
