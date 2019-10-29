--- base/include/android-base/endian.h.orig	2019-10-18 00:22:21 UTC
+++ base/include/android-base/endian.h
@@ -25,10 +25,15 @@
 
 #include <sys/endian.h>
 
-#elif defined(__GLIBC__)
+#elif defined(__GLIBC__) || defined(__DragonFly__) || defined(__FreeBSD__) || \
+      defined(__NetBSD__) || defined(__OpenBSD__)
 
+#if defined(__GLIBC__)
 /* glibc's <endian.h> is like bionic's <sys/endian.h>. */
 #include <endian.h>
+#else
+#include <sys/endian.h>
+#endif
 
 /* glibc keeps htons and htonl in <netinet/in.h>. */
 #include <netinet/in.h>
