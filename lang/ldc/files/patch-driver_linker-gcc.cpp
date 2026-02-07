--- driver/linker-gcc.cpp.orig	2022-07-20 17:05:27 UTC
+++ driver/linker-gcc.cpp
@@ -659,6 +659,8 @@ void ArgsBuilder::addDefaultPlatformLibs() {
   case llvm::Triple::Darwin:
   case llvm::Triple::MacOSX:
   case llvm::Triple::FreeBSD:
+    args.push_back("-lexecinfo"); // for static druntime
+  // fallthrough
   case llvm::Triple::NetBSD:
   case llvm::Triple::OpenBSD:
   case llvm::Triple::DragonFly:
