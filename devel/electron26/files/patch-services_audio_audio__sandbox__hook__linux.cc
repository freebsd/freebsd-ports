--- services/audio/audio_sandbox_hook_linux.cc.orig	2022-02-07 13:39:41 UTC
+++ services/audio/audio_sandbox_hook_linux.cc
@@ -143,6 +143,7 @@ void AddPulseAudioFilePermissions(
 }
 #endif
 
+#if !defined(OS_BSD)
 std::vector<BrokerFilePermission> GetAudioFilePermissions() {
   std::vector<BrokerFilePermission> permissions{
       BrokerFilePermission::ReadOnly("/dev/urandom"),
@@ -171,10 +172,12 @@ void LoadAudioLibraries() {
     }
   }
 }
+#endif
 
 }  // namespace
 
 bool AudioPreSandboxHook(sandbox::policy::SandboxLinux::Options options) {
+#if !defined(OS_BSD)
   LoadAudioLibraries();
   auto* instance = sandbox::policy::SandboxLinux::GetInstance();
   instance->StartBrokerProcess(MakeBrokerCommandSet({
@@ -194,6 +197,7 @@ bool AudioPreSandboxHook(sandbox::policy::SandboxLinux
   // TODO(https://crbug.com/850878) enable namespace sandbox. Currently, if
   // enabled, connect() on pulse native socket fails with ENOENT (called from
   // pa_context_connect).
+#endif
 
   return true;
 }
