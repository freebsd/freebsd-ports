--- services/service_manager/public/cpp/standalone_service/standalone_service.cc.orig	2019-03-15 06:37:32 UTC
+++ services/service_manager/public/cpp/standalone_service/standalone_service.cc
@@ -62,6 +62,8 @@ void RunStandaloneService(const StandaloneServiceCallb
             command_line.GetSwitchValueASCII(switches::kServiceSandboxType)),
         SandboxLinux::PreSandboxHook(), sandbox_options);
   }
+#elif defined(OS_BSD)
+  NOTIMPLEMENTED();
 #endif
 
   mojo::core::Init();
