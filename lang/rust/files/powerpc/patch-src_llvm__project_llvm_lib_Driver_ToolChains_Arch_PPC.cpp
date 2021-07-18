--- src/llvm-project/clang/lib/Driver/ToolChains/Arch/PPC.cpp.orig	2021-04-27 07:29:31.811399000 -0500
+++ src/llvm-project/clang/lib/Driver/ToolChains/Arch/PPC.cpp	2021-04-27 07:40:14.185257000 -0500
@@ -126,7 +126,8 @@ ppc::ReadGOTPtrMode ppc::getPPCReadGOTPtrMode(const Dr
                                               const ArgList &Args) {
   if (Args.getLastArg(options::OPT_msecure_plt))
     return ppc::ReadGOTPtrMode::SecurePlt;
-  if ((Triple.isOSFreeBSD() && Triple.getOSMajorVersion() >= 13) ||
+  if ((Triple.isOSFreeBSD() &&
+      (Triple.getOSMajorVersion() == 0 || Triple.getOSMajorVersion() >= 13)) ||
       Triple.isOSNetBSD() || Triple.isOSOpenBSD() || Triple.isMusl())
     return ppc::ReadGOTPtrMode::SecurePlt;
   else
