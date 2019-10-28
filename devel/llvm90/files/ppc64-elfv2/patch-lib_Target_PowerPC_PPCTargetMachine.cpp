--- lib/Target/PowerPC/PPCTargetMachine.cpp.orig	2019-07-04 07:43:51 UTC
+++ lib/Target/PowerPC/PPCTargetMachine.cpp
@@ -209,6 +209,20 @@ static PPCTargetMachine::PPCABI computeTargetABI(const
   if (TT.isMacOSX())
     return PPCTargetMachine::PPC_ABI_UNKNOWN;
 
+  if (TT.isOSFreeBSD()) {
+    switch (TT.getArch()) {
+    case Triple::ppc64le:
+    case Triple::ppc64:
+      if (TT.getOSMajorVersion() >= 13)
+        return PPCTargetMachine::PPC_ABI_ELFv2;
+      else
+        return PPCTargetMachine::PPC_ABI_ELFv1;
+    case Triple::ppc:
+    default:
+      return PPCTargetMachine::PPC_ABI_UNKNOWN;
+    }
+  }
+
   switch (TT.getArch()) {
   case Triple::ppc64le:
     return PPCTargetMachine::PPC_ABI_ELFv2;
