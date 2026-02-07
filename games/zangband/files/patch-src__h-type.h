--- src/h-type.h.orig
+++ src/h-type.h
@@ -103,6 +103,16 @@
 typedef signed short s16b;
 typedef unsigned short u16b;
 
+/* detect 64 bit GCC */
+#ifdef _LP64
+#ifndef L64
+#define L64 1
+#endif
+#ifndef L64B
+#define L64B 1
+#endif
+#endif
+
 /* Signed/Unsigned 32 bit value */
 #ifdef L64						/* 64 bit longs */
 typedef signed int s32b;
