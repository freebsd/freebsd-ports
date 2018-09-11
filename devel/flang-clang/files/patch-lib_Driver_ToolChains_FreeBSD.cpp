--- lib/Driver/ToolChains/FreeBSD.cpp.orig	2018-08-24 17:46:18 UTC
+++ lib/Driver/ToolChains/FreeBSD.cpp
@@ -196,6 +196,11 @@ void freebsd::Linker::ConstructJob(Compilation &C, con
     assert(Output.isNothing() && "Invalid output.");
   }
 
+  CmdArgs.push_back(Args.MakeArgString("-L%%LOCALBASE%%/flang/lib"));
+  CmdArgs.push_back(Args.MakeArgString("-L%%LOCALBASE%%/lib"));
+  CmdArgs.push_back(Args.MakeArgString("-L%%LOCALBASE%%/llvm60/lib"));
+  CmdArgs.push_back(Args.MakeArgString("-L/usr/lib"));
+
   if (!Args.hasArg(options::OPT_nostdlib, options::OPT_nostartfiles)) {
     const char *crt1 = nullptr;
     if (!Args.hasArg(options::OPT_shared)) {
@@ -263,6 +267,11 @@ void freebsd::Linker::ConstructJob(Compilation &C, con
       CmdArgs.push_back("--as-needed");
       CmdArgs.push_back("-lgcc_s");
       CmdArgs.push_back("--no-as-needed");
+    }
+
+    if (!Args.hasArg(options::OPT_noFlangLibs)) {
+      CmdArgs.push_back("-lpgmath");
+      CmdArgs.push_back("-lflang"); 
     }
 
     if (Args.hasArg(options::OPT_pthread)) {
