--- driver/linker-gcc.cpp.orig	2020-06-16 16:15:55 UTC
+++ driver/linker-gcc.cpp
@@ -647,6 +647,8 @@ void ArgsBuilder::addDefaultPlatformLibs() {
     args.push_back("-ldl");
   // fallthrough
   case llvm::Triple::FreeBSD:
+    args.push_back("-lexecinfo"); // for static druntime
+  // fallthrough
   case llvm::Triple::NetBSD:
   case llvm::Triple::OpenBSD:
   case llvm::Triple::DragonFly:
