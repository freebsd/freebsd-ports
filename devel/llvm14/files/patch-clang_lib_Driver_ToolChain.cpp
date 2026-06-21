--- clang/lib/Driver/ToolChain.cpp.orig
+++ clang/lib/Driver/ToolChain.cpp
@@ -110,6 +110,10 @@
 }
 
 bool ToolChain::defaultToIEEELongDouble() const {
+  if (getTriple().isOSFreeBSD() &&
+      getTriple().getArch() == llvm::Triple::ppc64le &&
+      getTriple().getOSMajorVersion() >= 16)
+    return true;
   return PPC_LINUX_DEFAULT_IEEELONGDOUBLE && getTriple().isOSLinux();
 }
 
