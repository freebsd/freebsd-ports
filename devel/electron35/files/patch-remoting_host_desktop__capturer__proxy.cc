--- remoting/host/desktop_capturer_proxy.cc.orig	2025-03-24 20:50:14 UTC
+++ remoting/host/desktop_capturer_proxy.cc
@@ -25,7 +25,7 @@
 #include "remoting/host/chromeos/frame_sink_desktop_capturer.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/environment.h"
 #include "base/nix/xdg_util.h"
 #include "remoting/host/linux/wayland_desktop_capturer.h"
@@ -90,7 +90,7 @@ void DesktopCapturerProxy::Core::CreateCapturer(
 
 #if BUILDFLAG(IS_CHROMEOS)
   capturer_ = std::make_unique<FrameSinkDesktopCapturer>();
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   static base::nix::SessionType session_type = base::nix::SessionType::kUnset;
   if (session_type == base::nix::SessionType::kUnset) {
     std::unique_ptr<base::Environment> env = base::Environment::Create();
@@ -297,7 +297,7 @@ bool DesktopCapturerProxy::SupportsFrameCallbacks() {
 bool DesktopCapturerProxy::SupportsFrameCallbacks() {
   DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return IsRunningWayland();
 #else
   return false;
