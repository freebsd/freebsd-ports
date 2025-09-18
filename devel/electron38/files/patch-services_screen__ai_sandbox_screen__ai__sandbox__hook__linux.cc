--- services/screen_ai/sandbox/screen_ai_sandbox_hook_linux.cc.orig	2025-08-26 20:49:50 UTC
+++ services/screen_ai/sandbox/screen_ai_sandbox_hook_linux.cc
@@ -70,6 +70,7 @@ bool ScreenAIPreSandboxHook(base::FilePath binary_path
     }
   }
 
+#if !BUILDFLAG(IS_BSD)
   auto* instance = sandbox::policy::SandboxLinux::GetInstance();
 
   std::vector<BrokerFilePermission> permissions{
@@ -91,6 +92,7 @@ bool ScreenAIPreSandboxHook(base::FilePath binary_path
                             sandbox::syscall_broker::COMMAND_OPEN}),
       permissions, options);
   instance->EngageNamespaceSandboxIfPossible();
+#endif
 
   return true;
 }
