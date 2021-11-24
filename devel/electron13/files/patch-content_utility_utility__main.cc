--- content/utility/utility_main.cc.orig	2021-07-15 19:13:39 UTC
+++ content/utility/utility_main.cc
@@ -89,6 +89,11 @@ int UtilityMain(const MainFunctionParams& parameters) 
   if (parameters.command_line.HasSwitch(switches::kUtilityStartupDialog))
     WaitForDebugger("Utility");
 
+#if defined(OS_FREEBSD)
+  sandbox::policy::Sandbox::Initialize(
+      sandbox::policy::SandboxTypeFromCommandLine(parameters.command_line));
+#endif
+
 #if defined(OS_LINUX) || defined(OS_CHROMEOS)
   // Initializes the sandbox before any threads are created.
   // TODO(jorgelo): move this after GTK initialization when we enable a strict
