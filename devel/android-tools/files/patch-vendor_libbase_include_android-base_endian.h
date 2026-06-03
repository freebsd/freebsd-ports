--- vendor/libbase/include/android-base/endian.h	2024-08-29 19:46:57.000000000 +0200
+++ vendor/libbase/include/android-base/endian.h	2026-03-21 13:55:33.956833000 +0100
@@ -25,6 +25,13 @@
 
 #include <sys/endian.h>
 
+#elif defined(__FreeBSD__)
+
+#include <sys/endian.h>
+#include <netinet/in.h>
+#define htonq(x) htobe64(x)
+#define ntohq(x) be64toh(x)
+
 #elif defined(__GLIBC__) || defined(ANDROID_HOST_MUSL) || defined(__linux__)
 
 /* glibc and musl's <endian.h> are like bionic's <sys/endian.h>. */
