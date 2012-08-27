
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
@@ -5153,7 +5184,9 @@
                                  const InputInfoList &Inputs,
                                  const ArgList &Args,
                                  const char *LinkingOutput) const {
-  const Driver &D = getToolChain().getDriver();
+  const toolchains::Linux& ToolChain =
+    static_cast<const toolchains::Linux&>(getToolChain());
+  const Driver &D = ToolChain.getDriver();
   ArgStringList CmdArgs;
 
   // Silence warning for "clang -g foo.o -o foo"
@@ -5167,6 +5200,9 @@
   if (!D.SysRoot.empty())
     CmdArgs.push_back(Args.MakeArgString("--sysroot=" + D.SysRoot));
 
+  if (Args.hasArg(options::OPT_pie))
+    CmdArgs.push_back("-pie");
+
   if (Args.hasArg(options::OPT_static)) {
     CmdArgs.push_back("-Bstatic");
   } else {
@@ -5179,8 +5215,8 @@
       CmdArgs.push_back("-dynamic-linker");
       CmdArgs.push_back("/libexec/ld-elf.so.1");
     }
-    if (getToolChain().getTriple().getOSMajorVersion() >= 9) {
-      llvm::Triple::ArchType Arch = getToolChain().getArch();
+    if (ToolChain.getTriple().getOSMajorVersion() >= 9) {
+      llvm::Triple::ArchType Arch = ToolChain.getArch();
       if (Arch == llvm::Triple::arm || Arch == llvm::Triple::sparc ||
           Arch == llvm::Triple::x86 || Arch == llvm::Triple::x86_64) {
         CmdArgs.push_back("--hash-style=both");
@@ -5191,12 +5227,12 @@
 
   // When building 32-bit code on FreeBSD/amd64, we have to explicitly
   // instruct ld in the base system to link 32-bit code.
-  if (getToolChain().getArchName() == "i386") {
+  if (ToolChain.getArchName() == "i386") {
     CmdArgs.push_back("-m");
     CmdArgs.push_back("elf_i386_fbsd");
   }
 
-  if (getToolChain().getArchName() == "powerpc") {
+  if (ToolChain.getArchName() == "powerpc") {
     CmdArgs.push_back("-m");
     CmdArgs.push_back("elf32ppc_fbsd");
   }
@@ -5210,29 +5246,32 @@
 
   if (!Args.hasArg(options::OPT_nostdlib) &&
       !Args.hasArg(options::OPT_nostartfiles)) {
-    if (!Args.hasArg(options::OPT_shared)) {
+    const char *crt1 = NULL;
+    if (!Args.hasArg(options::OPT_shared)){
       if (Args.hasArg(options::OPT_pg))
-        CmdArgs.push_back(Args.MakeArgString(
-                                getToolChain().GetFilePath("gcrt1.o")));
-      else {
-        const char *crt = Args.hasArg(options::OPT_pie) ? "Scrt1.o" : "crt1.o";
-        CmdArgs.push_back(Args.MakeArgString(
-                                getToolChain().GetFilePath(crt)));
-      }
-      CmdArgs.push_back(Args.MakeArgString(
-                              getToolChain().GetFilePath("crti.o")));
-      CmdArgs.push_back(Args.MakeArgString(
-                              getToolChain().GetFilePath("crtbegin.o")));
-    } else {
-      CmdArgs.push_back(Args.MakeArgString(
-                              getToolChain().GetFilePath("crti.o")));
-      CmdArgs.push_back(Args.MakeArgString(
-                              getToolChain().GetFilePath("crtbeginS.o")));
+        crt1 = "gcrt1.o";
+      else if (Args.hasArg(options::OPT_pie))
+        crt1 = "Scrt1.o";
+      else
+        crt1 = "crt1.o";
     }
+    if (crt1)
+      CmdArgs.push_back(Args.MakeArgString(ToolChain.GetFilePath(crt1)));
+
+    CmdArgs.push_back(Args.MakeArgString(ToolChain.GetFilePath("crti.o")));
+
+    const char *crtbegin;
+    if (Args.hasArg(options::OPT_static))
+      crtbegin = "crtbeginT.o";
+    else if (Args.hasArg(options::OPT_shared) || Args.hasArg(options::OPT_pie))
+      crtbegin = "crtbeginS.o";
+    else
+      crtbegin = "crtbegin.o";
+    CmdArgs.push_back(Args.MakeArgString(ToolChain.GetFilePath(crtbegin)));
   }
 
   Args.AddAllArgs(CmdArgs, options::OPT_L);
-  const ToolChain::path_list Paths = getToolChain().getFilePaths();
+  const ToolChain::path_list Paths = ToolChain.getFilePaths();
   for (ToolChain::path_list::const_iterator i = Paths.begin(), e = Paths.end();
        i != e; ++i)
     CmdArgs.push_back(Args.MakeArgString(StringRef("-L") + *i));
@@ -5243,12 +5282,12 @@
   Args.AddAllArgs(CmdArgs, options::OPT_Z_Flag);
   Args.AddAllArgs(CmdArgs, options::OPT_r);
 
-  AddLinkerInputs(getToolChain(), Inputs, Args, CmdArgs);
+  AddLinkerInputs(ToolChain, Inputs, Args, CmdArgs);
 
   if (!Args.hasArg(options::OPT_nostdlib) &&
       !Args.hasArg(options::OPT_nodefaultlibs)) {
     if (D.CCCIsCXX) {
-      getToolChain().AddCXXStdlibLibArgs(Args, CmdArgs);
+      ToolChain.AddCXXStdlibLibArgs(Args, CmdArgs);
       if (Args.hasArg(options::OPT_pg))
         CmdArgs.push_back("-lm_p");
       else
@@ -5301,20 +5340,20 @@
 
   if (!Args.hasArg(options::OPT_nostdlib) &&
       !Args.hasArg(options::OPT_nostartfiles)) {
-    if (!Args.hasArg(options::OPT_shared))
-      CmdArgs.push_back(Args.MakeArgString(getToolChain().GetFilePath(
-                                                                  "crtend.o")));
+    const char *crtend;
+    if (Args.hasArg(options::OPT_shared) || Args.hasArg(options::OPT_pie))
+      crtend = "crtendS.o";
     else
-      CmdArgs.push_back(Args.MakeArgString(getToolChain().GetFilePath(
-                                                                 "crtendS.o")));
-    CmdArgs.push_back(Args.MakeArgString(getToolChain().GetFilePath(
-                                                                    "crtn.o")));
+      crtend = "crtend.o";
+
+    CmdArgs.push_back(Args.MakeArgString(ToolChain.GetFilePath(crtend)));
+    CmdArgs.push_back(Args.MakeArgString(ToolChain.GetFilePath("crtn.o")));
   }
 
-  addProfileRT(getToolChain(), Args, CmdArgs, getToolChain().getTriple());
+  addProfileRT(ToolChain, Args, CmdArgs, ToolChain.getTriple());
 
   const char *Exec =
-    Args.MakeArgString(getToolChain().GetProgramPath("ld"));
+    Args.MakeArgString(ToolChain.GetProgramPath("ld"));
   C.addCommand(new Command(JA, *this, Exec, CmdArgs));
 }
 
