--- mono/io-layer/daemon.c.orig	Sat Nov 30 14:40:33 2002
+++ mono/io-layer/daemon.c	Sat Nov 30 14:43:38 2002
@@ -384,7 +384,7 @@
 
 		thread_handle->exitstatus=0;
 
-#ifdef _POSIX_THREAD_PROCESS_SHARED
+#if defined(_POSIX_THREAD_PROCESS_SHARED) && _POSIX_THREAD_PROCESS_SHARED != -1
 		_wapi_handle_lock_handle (handle);
 		_wapi_handle_set_signal_state (handle, TRUE, TRUE);
 		_wapi_handle_unlock_handle (handle);
@@ -442,7 +442,7 @@
 		_wapi_time_t_to_filetime (time (NULL),
 					  &process_handle_data->exit_time);
 
-#ifdef _POSIX_THREAD_PROCESS_SHARED
+#if defined(_POSIX_THREAD_PROCESS_SHARED) && _POSIX_THREAD_PROCESS_SHARED != -1
 		_wapi_handle_lock_handle (process_handle);
 		_wapi_handle_set_signal_state (process_handle, TRUE, TRUE);
 		_wapi_handle_unlock_handle (process_handle);
