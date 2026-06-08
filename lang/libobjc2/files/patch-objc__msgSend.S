--- objc_msgSend.S.orig	2025-09-16 15:03:00 UTC
+++ objc_msgSend.S
@@ -12,6 +12,8 @@
 #include "objc_msgSend.riscv64.S"
 #elif defined(__mips_n64) || defined(__mips_n32)
 #include "objc_msgSend.mips.S"
+#elif defined(__powerpc64__) && _CALL_ELF == 2
+#include "objc_msgSend.powerpc64.S"
 #else
 #warning objc_msgSend() not implemented for your architecture
 #endif
