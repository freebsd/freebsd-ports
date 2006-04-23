Index: qemu/target-mips/cpu.h
@@ -8,6 +8,13 @@
 #include "config.h"
 #include "softfloat.h"
 
+#ifdef __FreeBSD__
+#if __FreeBSD__ <= 4
+typedef uint32_t uint_fast8_t;
+typedef uint32_t uint_fast16_t;
+#endif
+#endif
+
 typedef union fpr_t fpr_t;
 union fpr_t {
     double d;
