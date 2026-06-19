--- driver/targetmachine.cpp.orig	2026-06-11 09:58:17 UTC
+++ driver/targetmachine.cpp
@@ -158,7 +158,7 @@
   case llvm::Triple::mips64el:
     return "n32";
   case llvm::Triple::ppc64:
-    return "elfv1";
+    return triple.isOSFreeBSD() ? "elfv2" : "elfv1";
   case llvm::Triple::ppc64le:
     return "elfv2";
   case llvm::Triple::riscv64:
