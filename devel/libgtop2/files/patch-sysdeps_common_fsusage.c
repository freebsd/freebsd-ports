--- sysdeps/common/fsusage.c.orig	Sun Oct 17 00:51:26 2004
+++ sysdeps/common/fsusage.c	Sun Oct 17 00:52:07 2004
@@ -253,8 +253,9 @@
   if (statvfs (path, &fsd) < 0)
     return;
 
-#if (defined(sun) || defined(__sun)) && (defined(__SVR4) || defined(__svr4__))
-  /* Solaris but not SunOS */
+#if (defined(sun) || defined(__sun)) && (defined(__SVR4) || defined(__svr4__)) \
+	|| defined(__FreeBSD__)
+  /* Solaris but not SunOS and FreeBSD */
   buf->block_size = fsd.f_frsize;
 #else
   /* else, including Linux */
