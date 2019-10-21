--- lib/Driver/ToolChains/FreeBSD.cpp.orig	2019-08-19 19:16:00 UTC
+++ lib/Driver/ToolChains/FreeBSD.cpp
@@ -217,6 +217,11 @@ void freebsd::Linker::ConstructJob(Compilation &C, con
     assert(Output.isNothing() && "Invalid output.");
   }
 
+  CmdArgs.push_back(Args.MakeArgString("-L/usr/local/flang/lib"));
+  CmdArgs.push_back(Args.MakeArgString("-L/usr/local/lib"));
+  CmdArgs.push_back(Args.MakeArgString("-L/usr/local/llvm70/lib"));
+  CmdArgs.push_back(Args.MakeArgString("-L/usr/lib"));
+
   if (!Args.hasArg(options::OPT_nostdlib, options::OPT_nostartfiles)) {
     const char *crt1 = nullptr;
     if (!Args.hasArg(options::OPT_shared)) {
@@ -290,6 +295,11 @@ void freebsd::Linker::ConstructJob(Compilation &C, con
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
