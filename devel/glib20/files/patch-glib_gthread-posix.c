--- glib/gthread-posix.c.orig	2014-09-22 15:42:12.000000000 +0200
+++ glib/gthread-posix.c	2014-09-28 09:46:56.659280343 +0200
@@ -98,7 +98,7 @@
   if G_UNLIKELY (mutex == NULL)
     g_thread_abort (errno, "malloc");
 
-#ifdef PTHREAD_ADAPTIVE_MUTEX_INITIALIZER_NP
+#if defined(PTHREAD_ADAPTIVE_MUTEX_INITIALIZER_NP) && !defined(__FreeBSD__)
   pthread_mutexattr_init (&attr);
   pthread_mutexattr_settype (&attr, PTHREAD_MUTEX_ADAPTIVE_NP);
   pattr = &attr;
@@ -107,7 +107,7 @@
   if G_UNLIKELY ((status = pthread_mutex_init (mutex, pattr)) != 0)
     g_thread_abort (status, "pthread_mutex_init");
 
-#ifdef PTHREAD_ADAPTIVE_MUTEX_NP
+#if defined(PTHREAD_ADAPTIVE_MUTEX_NP) && !defined(__FreeBSD__)
   pthread_mutexattr_destroy (&attr);
 #endif
 
