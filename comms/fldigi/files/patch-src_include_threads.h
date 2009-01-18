--- src/include/threads.h.orig	2009-01-05 14:01:07.000000000 -0500
+++ src/include/threads.h	2009-01-16 11:56:12.000000000 -0500
@@ -4,6 +4,7 @@
 #include <config.h>
 
 #include <pthread.h>
+#include <stdint.h>
 
 #include <semaphore.h>
 #if !HAVE_SEM_TIMEDWAIT
@@ -32,7 +33,8 @@
 #       define THREAD_ID_TYPE pthread_key_t
 #	define CREATE_THREAD_ID() pthread_key_create(&thread_id_, 0)
 #	define SET_THREAD_ID(x)   pthread_setspecific(thread_id_, (void *)(x))
-#	define GET_THREAD_ID()    (int)pthread_getspecific(thread_id_)
+//#	define GET_THREAD_ID()    (int)pthread_getspecific(thread_id_)
+#	define GET_THREAD_ID()    (uintptr_t)pthread_getspecific(thread_id_)
 #endif // USE_TLS
 
 
