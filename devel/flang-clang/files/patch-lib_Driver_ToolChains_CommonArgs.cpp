--- lib/Driver/ToolChains/CommonArgs.cpp.orig	2018-09-10 18:28:59 UTC
+++ lib/Driver/ToolChains/CommonArgs.cpp
@@ -183,6 +183,7 @@ void tools::AddLinkerInputs(const ToolChain &TC, const
     // Add Fortan "main" before the first linker input
     if (!SeenFirstLinkerInput) {
       if (needFortranMain(D, Args)) {
+        CmdArgs.push_back("-lflangrti");
         CmdArgs.push_back("-lflangmain");
       }
       SeenFirstLinkerInput = true;
@@ -206,6 +207,7 @@ void tools::AddLinkerInputs(const ToolChain &TC, const
   }
 
   if (!SeenFirstLinkerInput && needFortranMain(D, Args)) {
+    CmdArgs.push_back("-lflangrti");
     CmdArgs.push_back("-lflangmain");
   }
 
