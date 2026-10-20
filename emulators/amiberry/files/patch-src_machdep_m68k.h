--- src/machdep/m68k.h.orig	2026-10-20 02:04:08 UTC
+++ src/machdep/m68k.h
@@ -446,7 +446,7 @@
 
 #endif /* SAHF_SETO_PROFITABLE */
 
-#elif defined(CPU_riscv64) || defined(CPU_loongarch64) || defined(CPU_arm) || defined(CPU_AARCH64)
+#elif defined(CPU_riscv64) || defined(CPU_loongarch64) || defined(CPU_arm) || defined(CPU_AARCH64) || defined(CPU_powerpc)
 
 #ifdef __cplusplus
 # include <cstdlib>
@@ -458,7 +458,7 @@
  * Machine dependent structure for holding the 68k CCR flags
  */
 struct flag_struct {
-#if defined(CPU_riscv64) || defined(CPU_loongarch64) || defined(CPU_AARCH64)
+#if defined(CPU_riscv64) || defined(CPU_loongarch64) || defined(CPU_AARCH64) || (defined(CPU_powerpc) && defined(CPU_64_BIT))
 	uae_u64 nzcv;
 	uae_u64 x;
 #else
