--- mono/jit/debug.c.orig	Mon Jan 13 12:16:11 2003
+++ mono/jit/debug.c	Mon Jan 13 12:35:17 2003
@@ -37,9 +37,11 @@
 static gconstpointer debugger_notification_address = NULL;
 #ifndef PLATFORM_WIN32
 static pthread_cond_t debugger_thread_cond = PTHREAD_COND_INITIALIZER;
-static pthread_mutex_t debugger_thread_mutex = PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;
+static pthread_mutex_t debugger_thread_mutex = PTHREAD_MUTEX_INITIALIZER;
+static pthread_mutexattr_t debugger_thread_mutex_attr;
 static pthread_cond_t debugger_finished_cond = PTHREAD_COND_INITIALIZER;
-static pthread_mutex_t debugger_finished_mutex = PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;
+static pthread_mutex_t debugger_finished_mutex = PTHREAD_MUTEX_INITIALIZER;
+static pthread_mutexattr_t debugger_finished_mutex_attr;
 static pthread_cond_t debugger_start_cond = PTHREAD_COND_INITIALIZER;
 static pthread_mutex_t debugger_start_mutex = PTHREAD_MUTEX_INITIALIZER;
 static gboolean debugger_signalled = FALSE;
@@ -1389,6 +1391,17 @@
 	x86_ret (buf);
 
 #ifndef PLATFORM_WIN32
+
+	pthread_mutexattr_init(&debugger_thread_mutex_attr);
+	pthread_mutexattr_init(&debugger_finished_mutex_attr);
+	pthread_mutexattr_settype(&debugger_thread_mutex_attr,
+		PTHREAD_MUTEX_RECURSIVE);
+	pthread_mutexattr_settype(&debugger_finished_mutex_attr,
+		PTHREAD_MUTEX_RECURSIVE);
+	pthread_mutex_init(&debugger_thread_mutex, &debugger_thread_mutex_attr);
+	pthread_mutex_init(&debugger_finished_mutex,
+		&debugger_finished_mutex_attr);
+
 	pthread_mutex_lock (&debugger_start_mutex);
 
 	/*
