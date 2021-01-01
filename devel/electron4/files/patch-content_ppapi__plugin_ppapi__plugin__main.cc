--- content/ppapi_plugin/ppapi_plugin_main.cc.orig	2019-03-15 06:37:22 UTC
+++ content/ppapi_plugin/ppapi_plugin_main.cc
@@ -126,6 +126,8 @@ int PpapiPluginMain(const MainFunctionParams& paramete
       service_manager::SandboxTypeFromCommandLine(command_line),
       service_manager::SandboxLinux::PreSandboxHook(),
       service_manager::SandboxLinux::Options());
+#elif defined(OS_BSD)
+  NOTIMPLEMENTED();
 #endif
 
   ChildProcess ppapi_process;
