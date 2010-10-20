--- ./apr-0.9.19/threadproc/unix/procsup.c.orig	2006-09-20 16:04:09.000000000 +0000
+++ ./apr-0.9.19/threadproc/unix/procsup.c	2010-10-20 21:08:11.859622744 +0000
@@ -21,6 +21,7 @@
     int x;
 
     chdir("/");
+#ifndef FREEBSD_THREAD_HACK
 #if !defined(MPE) && !defined(OS2) && !defined(TPF) && !defined(BEOS)
     /* Don't detach for MPE because child processes can't survive the death of
      * the parent. */
@@ -56,6 +57,7 @@
         return errno;
     }
 #endif
+#endif
 
     /* close out the standard file descriptors */
     if (freopen("/dev/null", "r", stdin) == NULL) {
