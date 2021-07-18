--- src/llvm-project/llvm/lib/Target/PowerPC/PPCSubtarget.cpp.orig	2021-04-27 07:17:18.744914000 -0500
+++ src/llvm-project/llvm/lib/Target/PowerPC/PPCSubtarget.cpp	2021-04-27 07:25:23.450714000 -0500
@@ -151,7 +151,9 @@ void PPCSubtarget::initSubtargetFeatures(StringRef CPU
   if (IsPPC64 && has64BitSupport())
     Use64BitRegs = true;
 
-  if ((TargetTriple.isOSFreeBSD() && TargetTriple.getOSMajorVersion() >= 13) ||
+  if ((TargetTriple.isOSFreeBSD() &&
+      (TargetTriple.getOSMajorVersion() == 0 ||
+      TargetTriple.getOSMajorVersion() >= 13)) ||
       TargetTriple.isOSNetBSD() || TargetTriple.isOSOpenBSD() ||
       TargetTriple.isMusl())
     SecurePlt = true;
