--- module/owlib/src/c/ow_rwlock.c.orig	2015-01-11 01:31:32 UTC
+++ module/owlib/src/c/ow_rwlock.c
@@ -25,7 +25,6 @@ void my_rwlock_init(my_rwlock_t * rwlock
 	int semrc;
 	semrc = pthread_rwlock_init(rwlock, NULL);
 	if(semrc != 0) {
-		if ( 
 		LOCK_DEBUG("semrc=%d [%s] RWLOCK INIT", semrc, strerror(errno));
 		debug_crash();
 	}
