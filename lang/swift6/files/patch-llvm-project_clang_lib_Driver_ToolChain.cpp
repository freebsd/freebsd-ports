--- llvm-project/clang/lib/Driver/ToolChain.cpp.orig	2026-10-10 18:51:43 UTC
+++ llvm-project/clang/lib/Driver/ToolChain.cpp
@@ -193,6 +193,10 @@
 }
 
 bool ToolChain::defaultToIEEELongDouble() const {
+  if (getTriple().isOSFreeBSD() &&
+      getTriple().getArch() == llvm::Triple::ppc64le &&
+      getTriple().getOSMajorVersion() >= 16)
+    return true;
   return PPC_LINUX_DEFAULT_IEEELONGDOUBLE && getTriple().isOSLinux();
 }
 
