--- src/llvm-project/clang/lib/Basic/Targets.cpp.orig	2020-07-07 01:39:17.000000000 -0500
+++ src/llvm-project/clang/lib/Basic/Targets.cpp	2020-09-30 18:13:54.521751000 -0500
@@ -352,6 +352,8 @@ TargetInfo *AllocateTarget(const llvm::Triple &Triple,
     switch (os) {
     case llvm::Triple::Linux:
       return new LinuxTargetInfo<PPC64TargetInfo>(Triple, Opts);
+    case llvm::Triple::FreeBSD:
+      return new FreeBSDTargetInfo<PPC64TargetInfo>(Triple, Opts);
     case llvm::Triple::NetBSD:
       return new NetBSDTargetInfo<PPC64TargetInfo>(Triple, Opts);
     default:
