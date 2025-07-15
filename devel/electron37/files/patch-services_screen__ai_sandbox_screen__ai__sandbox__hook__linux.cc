--- services/screen_ai/sandbox/screen_ai_sandbox_hook_linux.cc.orig	2025-03-24 20:50:14 UTC
+++ services/screen_ai/sandbox/screen_ai_sandbox_hook_linux.cc
@@ -58,6 +58,7 @@ bool ScreenAIPreSandboxHook(base::FilePath binary_path
     }
   }
 
+#if !BUILDFLAG(IS_BSD)
   auto* instance = sandbox::policy::SandboxLinux::GetInstance();
 
   std::vector<BrokerFilePermission> permissions{
@@ -79,6 +80,7 @@ bool ScreenAIPreSandboxHook(base::FilePath binary_path
                             sandbox::syscall_broker::COMMAND_OPEN}),
       permissions, options);
   instance->EngageNamespaceSandboxIfPossible();
+#endif
 
   return true;
 }
