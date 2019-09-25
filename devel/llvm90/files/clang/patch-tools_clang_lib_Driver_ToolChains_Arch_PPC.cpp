--- tools/clang/lib/Driver/ToolChains/Arch/PPC.cpp.orig
+++ tools/clang/lib/Driver/ToolChains/Arch/PPC.cpp
@@ -115,7 +115,8 @@
                                               const ArgList &Args) {
   if (Args.getLastArg(options::OPT_msecure_plt))
     return ppc::ReadGOTPtrMode::SecurePlt;
-  if (Triple.isOSNetBSD() || Triple.isOSOpenBSD() || Triple.isMusl())
+  if ((Triple.isOSFreeBSD() && Triple.getOSMajorVersion() >= 13) ||
+      Triple.isOSNetBSD() || Triple.isOSOpenBSD() || Triple.isMusl())
     return ppc::ReadGOTPtrMode::SecurePlt;
   else
     return ppc::ReadGOTPtrMode::Bss;
