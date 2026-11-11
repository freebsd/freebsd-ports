--- src/util/arch/arm/cpuid_inline.h.orig	2026-11-11 07:42:02 UTC
+++ src/util/arch/arm/cpuid_inline.h
@@ -37,6 +37,8 @@
 #if !defined(HWCAP2_SVE2)
 #include <asm/hwcap.h>
 #endif
+#elif defined(__FreeBSD__)
+#include <sys/auxv.h>
 #endif
 
 #include "ue2common.h"
@@ -64,6 +66,26 @@ int check_sve2(void) {
         return 1;
     }
     return 0;
+}
+#elif defined(__FreeBSD__)
+static inline
+int check_sve(void) {
+    unsigned long hwcap = 0;
+    if (elf_aux_info(AT_HWCAP, &hwcap, sizeof(hwcap)) != 0) {
+        return 0;
+    }
+    return (hwcap & HWCAP_SVE) != 0;
+}
+
+/* The sve2 fat runtime variant is built with +sve2-bitperm. */
+static inline
+int check_sve2(void) {
+    unsigned long hwcap2 = 0;
+    if (!check_sve() ||
+        elf_aux_info(AT_HWCAP2, &hwcap2, sizeof(hwcap2)) != 0) {
+        return 0;
+    }
+    return (hwcap2 & HWCAP2_SVE2) && (hwcap2 & HWCAP2_SVEBITPERM);
 }
 #else
 static inline
