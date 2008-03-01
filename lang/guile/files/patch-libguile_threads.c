--- libguile/threads.c	2008-02-27 10:17:41.531443640 -0600
+++ libguile/threads.c	2008-02-27 10:25:44.309334685 -0600
@@ -593,7 +593,7 @@
 
 #if SCM_USE_PTHREAD_THREADS
 
-#if HAVE_PTHREAD_ATTR_GETSTACK && HAVE_PTHREAD_GETATTR_NP
+#if HAVE_PTHREAD_ATTR_GETSTACK && (HAVE_PTHREAD_GETATTR_NP || HAVE_PTHREAD_ATTR_GET_NP)
 /* This method for GNU/Linux and perhaps some other systems.
    It's not for MacOS X or Solaris 10, since pthread_getattr_np is not
    available on them.  */
@@ -606,8 +606,15 @@
   void *start, *end;
   size_t size;
 
+#if HAVE_PTHREAD_ATTR_GET_NP
+  pthread_attr_init (&attr);
+  pthread_attr_get_np (pthread_self (), &attr);
+  pthread_attr_getstack (&attr, &start, &size);
+  pthread_attr_destroy (&attr);
+#elif HAVE_PTHREAD_GETATTR_NP
   pthread_getattr_np (pthread_self (), &attr);
   pthread_attr_getstack (&attr, &start, &size);
+#endif
   end = (char *)start + size;
 
   /* XXX - pthread_getattr_np from LinuxThreads does not seem to work
