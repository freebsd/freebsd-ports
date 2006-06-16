
$FreeBSD$

--- src/spandsp/dc_restore.h.orig
+++ src/spandsp/dc_restore.h
@@ -109,5 +109,10 @@
 }
 #endif
 
+#ifndef INT16_MAX
+#define INT16_MAX 0x7fff
+#define INT16_MIN (-0x7fff-1)
+#endif
+
 #endif
 /*- End of file ------------------------------------------------------------*/
