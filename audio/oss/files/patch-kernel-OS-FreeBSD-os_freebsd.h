--- kernel/OS/FreeBSD/os_freebsd.h.orig	2007-06-12 17:32:57.000000000 -0400
+++ kernel/OS/FreeBSD/os_freebsd.h	2007-07-11 20:07:40.000000000 -0400
@@ -16,7 +16,6 @@
  * distribution. Please contact sales@opensound.com for further info.
  *
  */
-#define OS_VERSION "6"
 #define __inline__ inline
 #define __inline inline
 #define EXTERN_C extern "C"
@@ -55,6 +54,16 @@
 #include <vm/pmap.h>
 #include <sys/selinfo.h>
 
+#define	__FreeBSD_version_major	((__FreeBSD_version) / 100000)
+
+#if (__FreeBSD_version_major == 7)
+#define OS_VERSION	"7"
+#elif (__FreeBSD_version_major == 6)
+#define OS_VERSION	"6"
+#else
+#error Unsupported OS version
+#endif
+
 #undef timeout
 #define timeout oss_timeout
 #undef untimeout
