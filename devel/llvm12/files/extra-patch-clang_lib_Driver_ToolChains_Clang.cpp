--- clang/lib/Driver/ToolChains/Clang.cpp.orig	2021-08-11 19:51:00.122735000 +0200
+++ clang/lib/Driver/ToolChains/Clang.cpp	2021-08-11 19:51:24.346107000 +0200
@@ -1921,8 +1921,7 @@
   if (T.isOSBinFormatELF()) {
     switch (getToolChain().getArch()) {
     case llvm::Triple::ppc64: {
-      if ((T.isOSFreeBSD() && T.getOSMajorVersion() >= 13) ||
-          T.isOSOpenBSD() || T.isMusl())
+      if (T.isOSFreeBSD() || T.isOSOpenBSD() || T.isMusl())
         ABIName = "elfv2";
       else
         ABIName = "elfv1";
