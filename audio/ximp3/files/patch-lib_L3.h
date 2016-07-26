--- lib/L3.h.orig	2001-10-27 14:05:42 UTC
+++ lib/L3.h
@@ -39,6 +39,16 @@ ________________________________________
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
@@ -55,6 +65,8 @@ ________________________________________
 #define L_ENDIAN 0
 #endif
 
+#endif
+
 #ifndef L_ENDIAN
 #error Layer III L_ENDIAN must be defined 0 or 1
 #endif
