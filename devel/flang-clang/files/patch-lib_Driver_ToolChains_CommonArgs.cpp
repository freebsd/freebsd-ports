--- lib/Driver/ToolChains/CommonArgs.cpp.orig	2019-06-21 21:32:26 UTC
+++ lib/Driver/ToolChains/CommonArgs.cpp
@@ -187,6 +187,8 @@ void tools::AddLinkerInputs(const ToolChain &TC, const
     // Add Fortan "main" before the first linker input
     if (!SeenFirstLinkerInput) {
       if (needFortranMain(D, Args)) {
+        CmdArgs.push_back("-lexecinfo");
+        CmdArgs.push_back("-lflangrti");
         CmdArgs.push_back("-lflangmain");
       }
       SeenFirstLinkerInput = true;
@@ -210,6 +212,8 @@ void tools::AddLinkerInputs(const ToolChain &TC, const
   }
 
   if (!SeenFirstLinkerInput && needFortranMain(D, Args)) {
+    CmdArgs.push_back("-lexecinfo");
+    CmdArgs.push_back("-lflangrti");
     CmdArgs.push_back("-lflangmain");
   }
 
