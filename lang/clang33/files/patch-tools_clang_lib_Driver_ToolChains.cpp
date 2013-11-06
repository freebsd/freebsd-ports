
$FreeBSD$

--- tools/clang/lib/Driver/ToolChains.cpp.orig
+++ tools/clang/lib/Driver/ToolChains.cpp
@@ -1950,6 +1950,38 @@
   }
 }
 
+ToolChain::CXXStdlibType
+FreeBSD::GetCXXStdlibType(const ArgList &Args) const {
+  if (Arg *A = Args.getLastArg(options::OPT_stdlib_EQ)) {
+    StringRef Value = A->getValue();
+    if (Value == "libc++")
+      return ToolChain::CST_Libcxx;
+    if (Value == "libstdc++")
+      return ToolChain::CST_Libstdcxx;
+    getDriver().Diag(diag::err_drv_invalid_stdlib_name)
+      << A->getAsString(Args);
+  }
+
+  return getTriple().getOSMajorVersion() >= 10 ? ToolChain::CST_Libcxx :
+         ToolChain::CST_Libstdcxx;
+}
+
+void FreeBSD::AddClangCXXStdlibIncludeArgs(const ArgList &DriverArgs,
+                                          ArgStringList &CC1Args) const {
+  if (DriverArgs.hasArg(options::OPT_nostdlibinc) ||
+      DriverArgs.hasArg(options::OPT_nostdincxx))
+    return;
+
+  if (GetCXXStdlibType(DriverArgs) == ToolChain::CST_Libcxx)
+    addSystemInclude(DriverArgs, CC1Args,
+                     getDriver().SysRoot + "/usr/include/c++/v1");
+  else
+    addSystemInclude(DriverArgs, CC1Args,
+                     getDriver().SysRoot + "/usr/include/c++/4.2");
+  return;
+
+}
+
 /// NetBSD - NetBSD tool chain which can call as(1) and ld(1) directly.
 
 NetBSD::NetBSD(const Driver &D, const llvm::Triple& Triple, const ArgList &Args)
