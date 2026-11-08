--- third_party/libvpx/source/libvpx/vpx_ports/aarch64_cpudetect.c.orig	2025-01-27 17:37:37 UTC
+++ third_party/libvpx/source/libvpx/vpx_ports/aarch64_cpudetect.c
@@ -120,9 +120,23 @@ static int arm_get_cpu_caps(void) {
   return flags;
 }
 
-#elif defined(__linux__)  // end defined(VPX_USE_ANDROID_CPU_FEATURES)
+#elif defined(__linux__) || defined(__FreeBSD__)  // end defined(VPX_USE_ANDROID_CPU_FEATURES)
 
 #include <sys/auxv.h>
+
+#if defined(__FreeBSD__)
+static unsigned long getauxval(unsigned long type)
+{
+    /* Only AT_HWCAP* return unsigned long */
+    if (type != AT_HWCAP && type != AT_HWCAP2) {
+        return 0;
+    }
+
+    unsigned long ret = 0;
+    elf_aux_info(type, &ret, sizeof(ret));
+    return ret;
+}
+#endif
 
 // Define hwcap values ourselves: building with an old auxv header where these
 // hwcap values are not defined should not prevent features from being enabled.
