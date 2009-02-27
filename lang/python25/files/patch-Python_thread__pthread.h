
$FreeBSD$

--- Python/thread_pthread.h
+++ Python/thread_pthread.h
@@ -149,6 +149,7 @@
 {
 	pthread_t th;
 	int status;
+	sigset_t set, oset;
 #if defined(THREAD_STACK_SIZE) || defined(PTHREAD_SYSTEM_SCHED_SUPPORTED)
 	pthread_attr_t attrs;
 #endif
@@ -177,6 +178,8 @@
 #if defined(PTHREAD_SYSTEM_SCHED_SUPPORTED)
         pthread_attr_setscope(&attrs, PTHREAD_SCOPE_SYSTEM);
 #endif
+	sigfillset(&set);
+	SET_THREAD_SIGMASK(SIG_BLOCK, &set, &oset);
 
 	status = pthread_create(&th, 
 #if defined(THREAD_STACK_SIZE) || defined(PTHREAD_SYSTEM_SCHED_SUPPORTED)
@@ -188,6 +191,7 @@
 				 (void *)arg
 				 );
 
+	SET_THREAD_SIGMASK(SIG_SETMASK, &oset, NULL);
 #if defined(THREAD_STACK_SIZE) || defined(PTHREAD_SYSTEM_SCHED_SUPPORTED)
 	pthread_attr_destroy(&attrs);
 #endif
