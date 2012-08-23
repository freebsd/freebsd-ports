
$FreeBSD$

--- tools/clang/lib/Driver/Tools.cpp.orig
+++ tools/clang/lib/Driver/Tools.cpp
@@ -5119,17 +5119,48 @@
 
   // When building 32-bit code on FreeBSD/amd64, we have to explicitly
   // instruct as in the base system to assemble 32-bit code.
-  if (getToolChain().getArchName() == "i386")
+  if (getToolChain().getArch() == llvm::Triple::x86)
     CmdArgs.push_back("--32");
-
-  if (getToolChain().getArchName() == "powerpc")
+  else if (getToolChain().getArch() == llvm::Triple::ppc)
     CmdArgs.push_back("-a32");
+  else if (getToolChain().getArch() == llvm::Triple::mips ||
+           getToolChain().getArch() == llvm::Triple::mipsel ||
+           getToolChain().getArch() == llvm::Triple::mips64 ||
+           getToolChain().getArch() == llvm::Triple::mips64el) {
+    StringRef CPUName;
+    StringRef ABIName;
+    getMipsCPUAndABI(Args, getToolChain(), CPUName, ABIName);
 
-  // Set byte order explicitly
-  if (getToolChain().getArchName() == "mips")
-    CmdArgs.push_back("-EB");
-  else if (getToolChain().getArchName() == "mipsel")
-    CmdArgs.push_back("-EL");
+    CmdArgs.push_back("-march");
+    CmdArgs.push_back(CPUName.data());
+
+    // Convert ABI name to the GNU tools acceptable variant.
+    if (ABIName == "o32")
+      ABIName = "32";
+    else if (ABIName == "n64")
+      ABIName = "64";
+
+    CmdArgs.push_back("-mabi");
+    CmdArgs.push_back(ABIName.data());
+
+    if (getToolChain().getArch() == llvm::Triple::mips ||
+        getToolChain().getArch() == llvm::Triple::mips64)
+      CmdArgs.push_back("-EB");
+    else
+      CmdArgs.push_back("-EL");
+
+    Arg *LastPICArg = Args.getLastArg(options::OPT_fPIC, options::OPT_fno_PIC,
+                                      options::OPT_fpic, options::OPT_fno_pic,
+                                      options::OPT_fPIE, options::OPT_fno_PIE,
+                                      options::OPT_fpie, options::OPT_fno_pie);
+    if (LastPICArg &&
+        (LastPICArg->getOption().matches(options::OPT_fPIC) ||
+         LastPICArg->getOption().matches(options::OPT_fpic) ||
+         LastPICArg->getOption().matches(options::OPT_fPIE) ||
+         LastPICArg->getOption().matches(options::OPT_fpie))) {
+      CmdArgs.push_back("-KPIC");
+    }
+  }
 
   Args.AddAllArgValues(CmdArgs, options::OPT_Wa_COMMA,
                        options::OPT_Xassembler);
