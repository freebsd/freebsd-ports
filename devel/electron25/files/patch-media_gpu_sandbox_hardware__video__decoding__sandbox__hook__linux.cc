--- media/gpu/sandbox/hardware_video_decoding_sandbox_hook_linux.cc.orig	2023-05-25 00:41:58 UTC
+++ media/gpu/sandbox/hardware_video_decoding_sandbox_hook_linux.cc
@@ -15,7 +15,9 @@
 #include "media/gpu/vaapi/vaapi_wrapper.h"
 #endif
 
+#if !BUILDFLAG(IS_BSD)
 using sandbox::syscall_broker::BrokerFilePermission;
+#endif
 
 // TODO(b/195769334): the hardware video decoding sandbox is really only useful
 // when building with VA-API or V4L2 (otherwise, we're not really doing hardware
@@ -31,6 +33,7 @@ using sandbox::syscall_broker::BrokerFilePermission;
 namespace media {
 namespace {
 
+#if !BUILDFLAG(IS_BSD)
 void AllowAccessToRenderNodes(std::vector<BrokerFilePermission>& permissions,
                               bool include_sys_dev_char,
                               bool read_write) {
@@ -168,6 +171,7 @@ bool HardwareVideoDecodingPreSandboxHookForV4L2(
   return false;
 #endif  // BUILDFLAG(USE_V4L2_CODEC)
 }
+#endif
 
 }  // namespace
 
@@ -183,6 +187,7 @@ bool HardwareVideoDecodingPreSandboxHookForV4L2(
 //   (at least).
 bool HardwareVideoDecodingPreSandboxHook(
     sandbox::policy::SandboxLinux::Options options) {
+#if !BUILDFLAG(IS_BSD)
   using HardwareVideoDecodingProcessPolicy =
       sandbox::policy::HardwareVideoDecodingProcessPolicy;
   using PolicyType =
@@ -220,6 +225,7 @@ bool HardwareVideoDecodingPreSandboxHook(
   sandbox::policy::SandboxLinux::GetInstance()->StartBrokerProcess(
       command_set, permissions, sandbox::policy::SandboxLinux::PreSandboxHook(),
       options);
+#endif
   return true;
 }
 
