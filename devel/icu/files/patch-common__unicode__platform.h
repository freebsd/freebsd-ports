--- common/unicode/platform.h.orig	2013-09-12 03:46:50.000000000 +0400
+++ common/unicode/platform.h	2014-12-16 03:44:56.000000000 +0300
@@ -152,6 +152,9 @@
 #       define U_PLATFORM U_PF_DARWIN
 #   endif
 #elif defined(BSD) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__MirBSD__)
+#   if defined(__FreeBSD__)
+#       include <sys/endian.h>
+#   endif
 #   define U_PLATFORM U_PF_BSD
 #elif defined(sun) || defined(__sun)
     /* Check defined(__SVR4) || defined(__svr4__) to distinguish Solaris from SunOS? */
