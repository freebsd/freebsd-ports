--- mono/io-layer/wapi-private.h.orig	Sat Jul 20 14:31:18 2002
+++ mono/io-layer/wapi-private.h	Sat Nov 30 14:42:43 2002
@@ -105,7 +105,7 @@
 	guchar daemon[MONO_SIZEOF_SUNPATH];
 	_wapi_daemon_status daemon_running;
 	
-#ifdef _POSIX_THREAD_PROCESS_SHARED
+#if defined(_POSIX_THREAD_PROCESS_SHARED) && _POSIX_THREAD_PROCESS_SHARED != -1
 	mono_mutex_t signal_mutex;
 	pthread_cond_t signal_cond;
 #endif
@@ -133,7 +133,7 @@
  */
 struct _WapiHandlePrivate_list
 {
-#ifndef _POSIX_THREAD_PROCESS_SHARED
+#if !defined(_POSIX_THREAD_PROCESS_SHARED) || _POSIX_THREAD_PROCESS_SHARED == -1
 	mono_mutex_t signal_mutex;
 	pthread_cond_t signal_cond;
 #endif
