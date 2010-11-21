--- client/gvfsfusedaemon.c.orig	2010-11-12 16:42:49.000000000 +0100
+++ client/gvfsfusedaemon.c	2010-11-21 18:23:36.000000000 +0100
@@ -26,7 +26,9 @@
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/un.h>
+#ifdef __linux__
 #include <sys/vfs.h>
+#endif
 #include <sys/time.h>
 #include <unistd.h>
 #include <stdlib.h>
@@ -2340,7 +2342,9 @@
   subthread = g_thread_create ((GThreadFunc) subthread_main, NULL, FALSE, NULL);
 
   /* Indicate O_TRUNC support for open() */
+#ifdef FUSE_CAP_ATOMIC_O_TRUNC
   conn->want |= FUSE_CAP_ATOMIC_O_TRUNC;
+#endif
 
   return NULL;
 }
