--- src/rvjit/rvjit_arm.h.orig	2026-09-09 13:39:25 UTC
+++ src/rvjit/rvjit_arm.h
@@ -12,7 +12,7 @@ file, You can obtain one at https://mozilla.org/MPL/2.
 #include "mem_ops.h"
 #include "bit_ops.h"
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 #include <sys/auxv.h>
 #else
 #warning No RVJIT ARM CPU flags detection for target OS
@@ -44,7 +44,10 @@ static inline void rvjit_a32_test_cpu(void)
 {
 #ifdef __linux__
     rvjit_a32_hwcaps = getauxval(AT_HWCAP);
+#elif defined(__FreeBSD__)
+    elf_aux_info(AT_HWCAP, &rvjit_a32_hwcaps, sizeof rvjit_a32_hwcaps);
 #endif
+
     if (rvjit_a32_hwcaps & RVJIT_ARM_IDIVA) {
         rvvm_info("RVJIT detected ARM IDIV/UDIV extension");
     }
