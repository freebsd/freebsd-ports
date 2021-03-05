--- source/lib/byte_order.h.orig	2021-02-28 23:45:13 UTC
+++ source/lib/byte_order.h
@@ -33,7 +33,7 @@
 #ifndef BYTE_ORDER
 # define LITTLE_ENDIAN 0x4321
 # define BIG_ENDIAN    0x1234
-# if ARCH_IA32 || ARCH_IA64 || ARCH_AMD64 || ARCH_ALPHA || ARCH_ARM || ARCH_AARCH64 || ARCH_MIPS || ARCH_E2K || defined(__LITTLE_ENDIAN__)
+# if ARCH_IA32 || ARCH_IA64 || ARCH_AMD64 || ARCH_ALPHA || ARCH_ARM || ARCH_AARCH64 || ARCH_MIPS || ARCH_E2K || ARCH_PPC64 || defined(__LITTLE_ENDIAN__)
 #  define BYTE_ORDER LITTLE_ENDIAN
 # else
 #  define BYTE_ORDER BIG_ENDIAN
