--- pr/include/md/_freebsd.h.orig	2015-08-19 15:32:22.000000000 +0000
+++ pr/include/md/_freebsd.h	2015-11-04 11:38:01.257876000 +0000
@@ -29,6 +29,8 @@
 #define _PR_SI_ARCHITECTURE "powerpc64"
 #elif defined(__powerpc__)
 #define _PR_SI_ARCHITECTURE "powerpc"
+#elif defined(__aarch64__)
+#define _PR_SI_ARCHITECTURE "aarch64"
 #elif defined(__arm__)
 #define _PR_SI_ARCHITECTURE "arm"
 #elif defined(__mips64__)
