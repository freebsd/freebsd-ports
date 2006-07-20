
$FreeBSD$

--- src/spandsp/dc_restore.h.orig
+++ src/spandsp/dc_restore.h
@@ -53,6 +53,11 @@
     clean_sample = sample - (dc_bias >> 15); 
 */
 
+#ifndef INT16_MAX
+#define INT16_MAX 0x7fff
+#define INT16_MIN (-0x7fff-1)
+#endif
+
 /*!
     Zero DC restoration descriptor. This defines the working state for a single
     instance of DC content filter.
