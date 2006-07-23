--- ../pr/include/md/_freebsd.h.orig	Mon Nov 22 16:24:53 2004
+++ ../pr/include/md/_freebsd.h	Sun Jul 23 13:15:29 2006
@@ -106,6 +106,16 @@
 #define _PR_IPV6_V6ONLY_PROBE
 #endif
 
+#if (__FreeBSD_version >= 700016) || (__FreeBSD_version < 700000 && __FreeBSD_version >= 601103)
+#if defined(_PR_PTHREADS)
+#define _PR_HAVE_GETPROTO_R
+#define _PR_HAVE_5_ARG_GETPROTO_R
+#define _PR_HAVE_GETHOST_R
+#define _PR_HAVE_GETHOST_R_INT
+#define _PR_HAVE_THREADSAFE_GETHOST
+#endif
+#endif
+
 #define USE_SETJMP
 
 #ifndef _PR_PTHREADS
