--- clang/lib/Basic/Targets/PPC.h.orig
+++ clang/lib/Basic/Targets/PPC.h
@@ -481,7 +481,12 @@
       DataLayout += "-i64:64-i128:128-n32:64";
     }
 
-    if (Triple.isOSFreeBSD() || Triple.isOSOpenBSD() || Triple.isMusl()) {
+    if (Triple.isOSFreeBSD() && Triple.getArch() == llvm::Triple::ppc64le &&
+        Triple.getOSMajorVersion() >= 16) {
+      LongDoubleWidth = LongDoubleAlign = 128;
+      LongDoubleFormat = &llvm::APFloat::IEEEquad();
+    } else if (Triple.isOSFreeBSD() || Triple.isOSOpenBSD() ||
+               Triple.isMusl()) {
       LongDoubleWidth = LongDoubleAlign = 64;
       LongDoubleFormat = &llvm::APFloat::IEEEdouble();
     }
