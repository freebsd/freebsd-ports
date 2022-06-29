--- media/gpu/sandbox/hardware_video_decoding_sandbox_hook_linux.cc.orig	2022-05-25 04:01:04 UTC
+++ media/gpu/sandbox/hardware_video_decoding_sandbox_hook_linux.cc
@@ -14,12 +14,15 @@
 #include "media/gpu/vaapi/vaapi_wrapper.h"
 #endif
 
+#if !BUILDFLAG(IS_BSD)
 using sandbox::syscall_broker::BrokerFilePermission;
+#endif
 
 namespace media {
 
 bool HardwareVideoDecodingPreSandboxHook(
     sandbox::policy::SandboxLinux::Options options) {
+#if !BUILDFLAG(IS_BSD)
   sandbox::syscall_broker::BrokerCommandSet command_set;
   std::vector<BrokerFilePermission> permissions;
 
@@ -121,6 +124,7 @@ bool HardwareVideoDecodingPreSandboxHook(
   dlopen("/usr/lib/libv4l2.so", RTLD_NOW | RTLD_GLOBAL | RTLD_NODELETE);
 #endif  // defined(__aarch64__)
 #endif  // BUILDFLAG(USE_VAAPI)
+#endif
 
   return true;
 }
