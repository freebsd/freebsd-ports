--- mono/io-layer/handles.c.orig	Sat Nov 30 14:40:33 2002
+++ mono/io-layer/handles.c	Sat Nov 30 14:45:13 2002
@@ -153,7 +153,7 @@
 	pthread_mutexattr_init (&mutex_shared_attr);
 	pthread_condattr_init (&cond_shared_attr);
 
-#ifdef _POSIX_THREAD_PROCESS_SHARED
+#if defined(_POSIX_THREAD_PROCESS_SHARED) && _POSIX_THREAD_PROCESS_SHARED != -1
 	pthread_mutexattr_setpshared (&mutex_shared_attr,
 				      PTHREAD_PROCESS_SHARED);
 	pthread_condattr_setpshared (&cond_shared_attr,
@@ -881,7 +881,7 @@
  */
 int _wapi_handle_wait_signal (void)
 {
-#ifdef _POSIX_THREAD_PROCESS_SHARED
+#if defined(_POSIX_THREAD_PROCESS_SHARED) && _POSIX_THREAD_PROCESS_SHARED != -1
 	return(mono_cond_wait (&_wapi_shared_data->signal_cond,
 			       &_wapi_shared_data->signal_mutex));
 #else
@@ -903,7 +903,7 @@
 
 int _wapi_handle_timedwait_signal (struct timespec *timeout)
 {
-#ifdef _POSIX_THREAD_PROCESS_SHARED
+#if defined(_POSIX_THREAD_PROCESS_SHARED) && _POSIX_THREAD_PROCESS_SHARED != -1
 	return(mono_cond_timedwait (&_wapi_shared_data->signal_cond,
 				    &_wapi_shared_data->signal_mutex,
 				    timeout));
@@ -935,7 +935,7 @@
 
 int _wapi_handle_wait_signal_handle (gpointer handle)
 {
-#ifdef _POSIX_THREAD_PROCESS_SHARED
+#if defined(_POSIX_THREAD_PROCESS_SHARED) && _POSIX_THREAD_PROCESS_SHARED != -1
 	guint32 idx=GPOINTER_TO_UINT (handle);
 	
 	return(mono_cond_wait (&_wapi_shared_data->handles[idx].signal_cond,
@@ -961,7 +961,7 @@
 int _wapi_handle_timedwait_signal_handle (gpointer handle,
 					  struct timespec *timeout)
 {
-#ifdef _POSIX_THREAD_PROCESS_SHARED
+#if defined(_POSIX_THREAD_PROCESS_SHARED) && _POSIX_THREAD_PROCESS_SHARED != -1
 	guint32 idx=GPOINTER_TO_UINT (handle);
 	
 	return(mono_cond_timedwait (&_wapi_shared_data->handles[idx].signal_cond,
