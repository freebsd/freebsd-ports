--- src/spandsp/dc_restore.h.orig	Tue Jan 18 15:05:48 2005
+++ src/spandsp/dc_restore.h	Thu Jun 30 22:35:33 2005
@@ -85,6 +85,11 @@
 }
 /*- End of function --------------------------------------------------------*/
 
+#ifndef INT16_MAX
+#define INT16_MAX 0x7fff
+#define INT16_MIN (-0x7fff-1)
+#endif
+
 static inline int16_t saturate(int32_t amp)
 {
     if (amp > INT16_MAX)
