--- gen/target.cpp.orig	2026-06-11 09:58:17 UTC
+++ gen/target.cpp
@@ -317,7 +317,8 @@
     if (triple.getArch() == llvm::Triple::ppc64 ||
         triple.getArch() == llvm::Triple::ppc64le) {
       if (target.RealProperties.mant_dig == 113 &&
-          triple.getEnvironment() == llvm::Triple::GNU) {
+          (triple.getEnvironment() == llvm::Triple::GNU ||
+           triple.isOSFreeBSD())) {
         return "u9__ieee128";
       }
       if (target.RealProperties.mant_dig == 106) {
