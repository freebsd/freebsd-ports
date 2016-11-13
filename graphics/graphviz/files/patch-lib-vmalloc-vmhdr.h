--- lib/vmalloc/vmhdr.h.orig	2016-11-07 02:32:54.935418000 +0000
+++ lib/vmalloc/vmhdr.h	2016-11-07 02:38:16.506108000 +0000
@@ -20,6 +20,10 @@
 #ifndef _BLD_vmalloc
 #define _BLD_vmalloc	1
 #endif
+#if defined(__FreeBSD__) && defined(__aarch64__)
+/* No sbrk on FreeBSD/AArch64 */
+#define _std_malloc	1
+#endif
 #ifdef WIN32
 #include <io.h>
 #endif
