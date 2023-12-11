--- third_party/libaom/source/libaom/aom_ports/aarch64_cpudetect.c.orig	2023-10-19 19:59:38 UTC
+++ third_party/libaom/source/libaom/aom_ports/aarch64_cpudetect.c
@@ -85,13 +85,35 @@ static int arm_get_cpu_caps(void) {
   return flags;
 }
 
-#elif defined(ANDROID_USE_CPU_FEATURES_LIB)
+#elif defined(ANDROID_USE_CPU_FEATURES_LIB) || defined(__FreeBSD__)
 
 static int arm_get_cpu_caps(void) {
   int flags = 0;
 #if HAVE_NEON
   flags |= HAS_NEON;  // Neon is mandatory in Armv8.0-A.
 #endif  // HAVE_NEON
+  return flags;
+}
+
+#elif defined(__OpenBSD__)
+#include <sys/sysctl.h>
+#include <machine/cpu.h>
+#include <machine/armreg.h>
+
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
+  if (ID_AA64ISAR0_AES(cpu_id) >= ID_AA64ISAR0_CRC32_BASE)
+    flags |= HAS_ARM_CRC32;
+
   return flags;
 }
 
