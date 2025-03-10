--- client/gvfsfusedaemon.c.orig	2012-05-15 20:01:49.000000000 +0200
+++ client/gvfsfusedaemon.c	2012-05-31 14:00:26.000000000 +0200
@@ -2361,7 +2361,9 @@
   subthread = g_thread_new ("gvfs-fuse-sub", (GThreadFunc) subthread_main, NULL);
 
   /* Indicate O_TRUNC support for open() */
+#ifdef FUSE_CAP_ATOMIC_O_TRUNC
   conn->want |= FUSE_CAP_ATOMIC_O_TRUNC;
+#endif
 
   return NULL;
 }
