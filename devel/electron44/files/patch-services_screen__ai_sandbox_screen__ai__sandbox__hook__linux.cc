--- services/screen_ai/sandbox/screen_ai_sandbox_hook_linux.cc.orig	2026-06-23 23:37:18 UTC
+++ services/screen_ai/sandbox/screen_ai_sandbox_hook_linux.cc
@@ -59,6 +59,7 @@ bool ScreenAIPreSandboxHook(base::FilePath binary_path
     }
   }
 
+#if !BUILDFLAG(IS_BSD)
   auto* instance = sandbox::policy::SandboxLinux::GetInstance();
 
   std::vector<BrokerFilePermission> permissions{
@@ -80,6 +81,7 @@ bool ScreenAIPreSandboxHook(base::FilePath binary_path
                             sandbox::syscall_broker::COMMAND_OPEN}),
       permissions, options);
   instance->EngageNamespaceSandboxIfPossible();
+#endif
 
   return true;
 }
