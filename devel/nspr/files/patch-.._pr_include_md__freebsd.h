--- ../pr/include/md/_freebsd.h.orig	Sat Apr 22 17:14:55 2006
+++ ../pr/include/md/_freebsd.h	Sat Apr 22 17:14:47 2006
@@ -106,6 +106,11 @@
 #define _PR_IPV6_V6ONLY_PROBE
 #endif
 
+#if (__FreeBSD_version >= 700016) || (__FreeBSD_version < 700000 && __FreeBSD_version >= 601103)
+#define _PR_HAVE_GETPROTO_R
+#define _PR_HAVE_5_ARG_GETPROTO_R
+#endif
+
 #define USE_SETJMP
 
 #ifndef _PR_PTHREADS
