--- src/pj_mutex.c.orig	2015-05-25 16:01:14.724346000 +0800
+++ src/pj_mutex.c	2015-05-25 16:03:52.777784000 +0800
@@ -118,11 +118,7 @@
         pthread_mutex_lock( &pj_precreated_lock);
 
         pthread_mutexattr_init(&mutex_attr);
-#ifndef PTHREAD_MUTEX_RECURSIVE
-        pthread_mutexattr_settype(&mutex_attr, PTHREAD_MUTEX_RECURSIVE_NP);
-#else
         pthread_mutexattr_settype(&mutex_attr, PTHREAD_MUTEX_RECURSIVE);
-#endif
         pthread_mutex_init(&pj_core_lock, &mutex_attr);
         pj_core_lock_created = 1;
 
