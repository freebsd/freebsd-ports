--- mono/io-layer/handles-private.h.orig	Sat Nov 30 14:47:32 2002
+++ mono/io-layer/handles-private.h	Sat Nov 30 14:48:28 2002
@@ -103,7 +103,7 @@
 		/* Tell everyone blocking on multiple handles that something
 		 * was signalled
 		 */
-#ifdef _POSIX_THREAD_PROCESS_SHARED
+#if defined(_POSIX_THREAD_PROCESS_SHARED) && _POSIX_THREAD_PROCESS_SHARED != -1
 		mono_mutex_lock (&_wapi_shared_data->signal_mutex);
 		pthread_cond_broadcast (&_wapi_shared_data->signal_cond);
 		mono_mutex_unlock (&_wapi_shared_data->signal_mutex);
@@ -138,7 +138,7 @@
 #ifdef DEBUG
 	g_message (G_GNUC_PRETTY_FUNCTION ": lock global signal mutex");
 #endif
-#ifdef _POSIX_THREAD_PROCESS_SHARED
+#if defined(_POSIX_THREAD_PROCESS_SHARED) && _POSIX_THREAD_PROCESS_SHARED != -1
 	return(mono_mutex_lock (&_wapi_shared_data->signal_mutex));
 #else
 	return(mono_mutex_lock (&_wapi_private_data->signal_mutex));
@@ -150,7 +150,7 @@
 #ifdef DEBUG
 	g_message (G_GNUC_PRETTY_FUNCTION ": unlock global signal mutex");
 #endif
-#ifdef _POSIX_THREAD_PROCESS_SHARED
+#if defined(_POSIX_THREAD_PROCESS_SHARED) && _POSIX_THREAD_PROCESS_SHARED != -1
 	return(mono_mutex_unlock (&_wapi_shared_data->signal_mutex));
 #else
 	return(mono_mutex_unlock (&_wapi_private_data->signal_mutex));
