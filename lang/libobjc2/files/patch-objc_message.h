--- objc/message.h.orig	2025-09-16 15:03:00 UTC
+++ objc/message.h
@@ -10,7 +10,8 @@
     defined(__mips_n64) || defined(__mips_n32) ||                              \
     defined(__ARM_ARCH_ISA_A64) ||                                             \
     (defined(__riscv) && __riscv_xlen == 64 &&                                 \
-     defined(__riscv_float_abi_double))
+     defined(__riscv_float_abi_double)) ||                                     \
+    (defined(__powerpc64__) && _CALL_ELF == 2)
 
 // Define __GNUSTEP_MSGSEND__ if available
 #ifndef __GNUSTEP_MSGSEND__
