--- libsoxr/src/soxr.c.orig	2022-11-09 12:37:21 UTC
+++ libsoxr/src/soxr.c
@@ -12,10 +12,12 @@
 
 #if AVUTIL_FOUND
   #include <libavutil/cpu.h>
-#elif HAVE_GETAUXVAL && defined(__arm__)
+#elif HAVE_GETAUXVAL
   #include <sys/auxv.h>
+#ifdef __linux__
   #include <asm/hwcap.h>
 #endif
+#endif
 
 
 
@@ -243,7 +245,16 @@ soxr_io_spec_t soxr_io_spec(
   #endif
 #endif
 
+#ifdef __FreeBSD__
+  static unsigned long getauxval(int aux)
+  {
+    unsigned long val = 0;
 
+    elf_aux_info(aux, &val, sizeof val);
+
+    return val;
+  }
+#endif
 
 #if WITH_CR32S && WITH_CR32
   static bool cpu_has_simd32(void)
