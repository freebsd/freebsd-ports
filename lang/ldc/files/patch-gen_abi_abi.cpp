--- gen/abi/abi.cpp.orig	2026-06-11 12:57:35 UTC
+++ gen/abi/abi.cpp
@@ -273,8 +273,12 @@
   case llvm::Triple::riscv64:
     return getRISCV64TargetABI();
   case llvm::Triple::ppc:
+    return getPPCTargetABI(false);
   case llvm::Triple::ppc64:
-    return getPPCTargetABI(global.params.targetTriple->isArch64Bit());
+    // FreeBSD powerpc64 is big-endian but uses the ELFv2 ABI, like ppc64le.
+    if (global.params.targetTriple->isOSFreeBSD())
+      return getPPC64LETargetABI();
+    return getPPCTargetABI(true);
   case llvm::Triple::ppc64le:
     return getPPC64LETargetABI();
   case llvm::Triple::aarch64:
