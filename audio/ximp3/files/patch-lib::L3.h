--- lib/L3.h.orig	Sat Oct 27 23:05:42 2001
+++ lib/L3.h	Mon Aug 18 20:18:00 2003
@@ -39,6 +39,16 @@
 #define GLOBAL_GAIN_SCALE (4*15)
 /* #define GLOBAL_GAIN_SCALE 0 */
 
+#include <sys/types.h>
+
+#ifdef BYTE_ORDER
+#if BYTE_ORDER == LITTLE_ENDIAN
+#define L_ENDIAN 1
+#else
+#define L_ENDIAN 0
+#endif
+#else
+
 #ifdef i386
 #define L_ENDIAN 1
 #endif
@@ -53,6 +63,8 @@
 
 #ifdef sparc
 #define L_ENDIAN 0
+#endif
+
 #endif
 
 #ifndef L_ENDIAN
