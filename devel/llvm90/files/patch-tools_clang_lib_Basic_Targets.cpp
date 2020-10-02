--- tools/clang/lib/Basic/Targets.cpp.orig	2020-09-27 10:34:55 UTC
+++ tools/clang/lib/Basic/Targets.cpp
@@ -357,6 +357,8 @@ TargetInfo *AllocateTarget(const llvm::Triple &Triple,
     switch (os) {
     case llvm::Triple::Linux:
       return new LinuxTargetInfo<PPC64TargetInfo>(Triple, Opts);
+    case llvm::Triple::FreeBSD:
+      return new FreeBSDTargetInfo<PPC64TargetInfo>(Triple, Opts);
     case llvm::Triple::NetBSD:
       return new NetBSDTargetInfo<PPC64TargetInfo>(Triple, Opts);
     default:
