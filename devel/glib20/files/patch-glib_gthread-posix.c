--- glib/gthread-posix.c.orig	2012-11-10 03:24:06.000000000 +0000
+++ glib/gthread-posix.c	2012-11-12 18:06:36.000000000 +0000
@@ -89,7 +89,7 @@
   if G_UNLIKELY (mutex == NULL)
     g_thread_abort (errno, "malloc");
 
-#ifdef PTHREAD_ADAPTIVE_MUTEX_INITIALIZER_NP
+#if defined(PTHREAD_ADAPTIVE_MUTEX_INITIALIZER_NP) && !defined(__FreeBSD__)
   {
     pthread_mutexattr_t attr;
     pthread_mutexattr_init (&attr);
@@ -101,7 +101,7 @@
   if G_UNLIKELY ((status = pthread_mutex_init (mutex, pattr)) != 0)
     g_thread_abort (status, "pthread_mutex_init");
 
-#ifdef PTHREAD_ADAPTIVE_MUTEX_NP
+#if defined(PTHREAD_ADAPTIVE_MUTEX_NP) && !defined(__FreeBSD__)
   pthread_mutexattr_destroy (&attr);
 #endif
 
