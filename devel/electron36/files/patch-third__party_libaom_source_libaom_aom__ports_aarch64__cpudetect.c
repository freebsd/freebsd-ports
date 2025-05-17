--- third_party/libaom/source/libaom/aom_ports/aarch64_cpudetect.c.orig	2025-01-27 17:37:37 UTC
+++ third_party/libaom/source/libaom/aom_ports/aarch64_cpudetect.c
@@ -127,9 +127,45 @@ static int arm_get_cpu_caps(void) {
   return flags;
 }
 
-#elif defined(__linux__)  // end defined(AOM_USE_ANDROID_CPU_FEATURES)
+#elif defined(__OpenBSD__)
+#include <sys/sysctl.h>
+#include <machine/cpu.h>
+#include <machine/armreg.h>
 
+static int arm_get_cpu_caps(void) {
+  int flags = 0;
+  int isar0_mib[] = { CTL_MACHDEP, CPU_ID_AA64ISAR0 };
+  uint64_t cpu_id = 0;
+  size_t len = sizeof(cpu_id);
+
+  flags |= HAS_NEON;  // Neon is mandatory in Armv8.0-A.
+
+  if (sysctl(isar0_mib, 2, &cpu_id, &len, NULL, 0) < 0)
+    return flags;
+
+  if (ID_AA64ISAR0_CRC32(cpu_id) >= ID_AA64ISAR0_CRC32_BASE)
+    flags |= HAS_ARM_CRC32;
+
+  return flags;
+}
+
+#elif defined(__linux__) || defined(__FreeBSD__)  // end defined(AOM_USE_ANDROID_CPU_FEATURES)
+
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
