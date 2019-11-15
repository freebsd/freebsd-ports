--- clang/lib/Basic/Targets/PPC.h.orig	2019-07-09 13:32:26 UTC
+++ clang/lib/Basic/Targets/PPC.h
@@ -374,12 +374,29 @@ class LLVM_LIBRARY_VISIBILITY PPC64TargetInfo : public
     IntMaxType = SignedLong;
     Int64Type = SignedLong;
 
+    if (Triple.getEnvironment() != llvm::Triple::UnknownEnvironment) {
+      switch (Triple.getEnvironment()){
+        case llvm::Triple::ELFv1:
+          ABI = "elfv1";
+          break;
+	default:
+          ABI = "elfv2";
+	break;
+      }
+    } else {
+      if ((Triple.getOS() == llvm::Triple::FreeBSD) &&
+	      (Triple.getOSMajorVersion() < 13)) {
+        ABI = "elfv1";
+      } else {
+        ABI = "elfv2";
+      }
+    }
+
+
     if ((Triple.getArch() == llvm::Triple::ppc64le)) {
       resetDataLayout("e-m:e-i64:64-n32:64");
-      ABI = "elfv2";
     } else {
       resetDataLayout("E-m:e-i64:64-n32:64");
-      ABI = Triple.getEnvironment() == llvm::Triple::ELFv2 ? "elfv2" : "elfv1";
     }
 
     if (Triple.getOS() == llvm::Triple::AIX)
