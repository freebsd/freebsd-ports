--- plugins/rtjpeg/RTjpeg.h.orig	Tue Jun  4 05:04:22 2002
+++ plugins/rtjpeg/RTjpeg.h	Sat Aug 10 03:35:52 2002
@@ -31,8 +31,12 @@
 		South Africa
 */
 
+#ifdef HAVE_STDINT_H
 #ifndef _STDINT_H
 #include <stdint.h>
+#endif
+#else
+#include <inttypes.h>
 #endif
 
 #ifdef __RTJPEG_INTERNAL__
