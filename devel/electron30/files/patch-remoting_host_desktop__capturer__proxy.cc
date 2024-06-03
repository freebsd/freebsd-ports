--- remoting/host/desktop_capturer_proxy.cc.orig	2024-04-15 20:34:03 UTC
+++ remoting/host/desktop_capturer_proxy.cc
@@ -26,7 +26,7 @@
 #include "remoting/host/chromeos/frame_sink_desktop_capturer.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/environment.h"
 #include "base/nix/xdg_util.h"
 #include "remoting/host/linux/wayland_desktop_capturer.h"
@@ -91,7 +91,7 @@ void DesktopCapturerProxy::Core::CreateCapturer(
 
 #if BUILDFLAG(IS_CHROMEOS_ASH)
   capturer_ = std::make_unique<FrameSinkDesktopCapturer>();
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   static base::nix::SessionType session_type = base::nix::SessionType::kUnset;
   if (session_type == base::nix::SessionType::kUnset) {
     std::unique_ptr<base::Environment> env = base::Environment::Create();
@@ -298,7 +298,7 @@ bool DesktopCapturerProxy::SupportsFrameCallbacks() {
 bool DesktopCapturerProxy::SupportsFrameCallbacks() {
   DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return IsRunningWayland();
 #else
   return false;
