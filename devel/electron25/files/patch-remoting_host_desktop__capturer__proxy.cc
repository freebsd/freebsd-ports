--- remoting/host/desktop_capturer_proxy.cc.orig	2023-03-30 00:33:55 UTC
+++ remoting/host/desktop_capturer_proxy.cc
@@ -30,7 +30,7 @@
 #include "remoting/host/chromeos/frame_sink_desktop_capturer.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/environment.h"
 #include "base/nix/xdg_util.h"
 #include "remoting/host/linux/wayland_desktop_capturer.h"
@@ -99,7 +99,7 @@ void DesktopCapturerProxy::Core::CreateCapturer(
     capturer_ = std::make_unique<webrtc::DesktopCapturerDifferWrapper>(
         std::make_unique<AuraDesktopCapturer>());
   }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   static base::nix::SessionType session_type = base::nix::SessionType::kUnset;
   if (session_type == base::nix::SessionType::kUnset) {
     std::unique_ptr<base::Environment> env = base::Environment::Create();
@@ -303,7 +303,7 @@ void DesktopCapturerProxy::OnMetadata(webrtc::DesktopC
 bool DesktopCapturerProxy::SupportsFrameCallbacks() {
   DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return IsRunningWayland();
 #else
   return false;
