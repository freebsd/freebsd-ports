    [PowerPC64LE] Fix platform definitions for powerpc64le-*-freebsd*
    
    Teach clang that powerpc64le-*-freebsd* is a valid triple.
    
    This is already in upstream clang, but was too late for llvm 11.0.0.
    Apply it directly for now, until it can be backported to llvm 11.0.1.
    
    See upstream https://reviews.llvm.org/D73425 for details.
    
    Reviewed by:    dim (upstream version), emaste
    Approved by:    emaste
    Differential Revision:  https://reviews.freebsd.org/D26400

--- tools/clang/lib/Basic/Targets.cpp.orig
+++ tools/clang/lib/Basic/Targets.cpp
@@ -358,6 +358,8 @@
     switch (os) {
     case llvm::Triple::Linux:
       return new LinuxTargetInfo<PPC64TargetInfo>(Triple, Opts);
+    case llvm::Triple::FreeBSD:
+      return new FreeBSDTargetInfo<PPC64TargetInfo>(Triple, Opts);
     case llvm::Triple::NetBSD:
       return new NetBSDTargetInfo<PPC64TargetInfo>(Triple, Opts);
     case llvm::Triple::OpenBSD:
