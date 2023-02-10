--- third_party/skia/src/core/SkCpu.cpp.orig	2022-04-21 18:48:31 UTC
+++ third_party/skia/src/core/SkCpu.cpp
@@ -73,6 +73,42 @@
         return features;
     }
 
+#elif defined(SK_CPU_ARM64) && defined(__OpenBSD__)
+    #include <sys/sysctl.h>
+    #include <machine/cpu.h>
+    #include <machine/armreg.h>
+
+    static uint32_t read_cpu_features() {
+      int isar0_mib[] = { CTL_MACHDEP, CPU_ID_AA64ISAR0 };
+      size_t len = sizeof(uint64_t);
+      uint64_t cpu_id = 0;
+      uint32_t features = 0;
+
+      if (sysctl(isar0_mib, 2, &cpu_id, &len, NULL, 0) == 0) {
+        if (ID_AA64ISAR0_CRC32(cpu_id) >= ID_AA64ISAR0_CRC32_BASE)
+          features |= SkCpu::CRC32;
+      }
+
+      return features;
+    }
+
+#elif defined(SK_CPU_ARM64) && defined(__FreeBSD__)
+    #include <machine/armreg.h>
+    #ifndef ID_AA64ISAR0_CRC32_VAL
+    #define ID_AA64ISAR0_CRC32_VAL ID_AA64ISAR0_CRC32
+    #endif
+
+    static uint32_t read_cpu_features() {
+      uint32_t features = 0;
+      uint64_t id_aa64isar0;
+
+      id_aa64isar0 = READ_SPECIALREG(id_aa64isar0_el1);
+      if (ID_AA64ISAR0_CRC32_VAL(id_aa64isar0) == ID_AA64ISAR0_CRC32_BASE) {
+        features |= SkCpu::CRC32;
+      }
+      return features;
+    }
+
 #elif defined(SK_CPU_ARM64) && __has_include(<sys/auxv.h>)
     #include <sys/auxv.h>
 
