--- src/include/threads.h.orig	2008-08-23 12:34:24.000000000 -0400
+++ src/include/threads.h	2008-08-23 12:32:50.000000000 -0400
@@ -46,6 +46,7 @@
 #include <config.h>
 
 #include <pthread.h>
+#include <stdint.h>
 
 typedef pthread_t			Fl_Thread;
 typedef pthread_mutex_t		Fl_Mutex;
@@ -87,7 +88,8 @@
 	extern pthread_key_t thread_id_;
 #	define CREATE_THREAD_ID() pthread_key_create(&thread_id_, 0);
 #	define SET_THREAD_ID(x)   pthread_setspecific(thread_id_, (void *)(x))
-#	define GET_THREAD_ID()    (int)pthread_getspecific(thread_id_)
+//#	define GET_THREAD_ID()    (int)pthread_getspecific(thread_id_)
+#	define GET_THREAD_ID()    (uintptr_t)pthread_getspecific(thread_id_)
 #endif // USE_TLS
 
 #include "fl_lock.h"
