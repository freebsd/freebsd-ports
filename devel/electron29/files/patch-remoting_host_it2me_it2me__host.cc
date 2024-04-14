--- remoting/host/it2me/it2me_host.cc.orig	2024-02-21 00:20:51 UTC
+++ remoting/host/it2me/it2me_host.cc
@@ -52,7 +52,7 @@
 #include "remoting/host/chromeos/features.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "remoting/host/linux/wayland_manager.h"
 #include "remoting/host/linux/wayland_utils.h"
 #endif  // BUILDFLAG(IS_LINUX)
@@ -178,7 +178,7 @@ void It2MeHost::Connect(
 
   OnPolicyUpdate(std::move(policies));
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (IsRunningWayland()) {
     WaylandManager::Get()->Init(host_context_->ui_task_runner());
   }
@@ -338,7 +338,7 @@ void It2MeHost::ConnectOnNetworkThread(
 
   // Set up the desktop environment options.
   DesktopEnvironmentOptions options(DesktopEnvironmentOptions::CreateDefault());
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (IsRunningWayland()) {
     options.desktop_capture_options()->set_prefer_cursor_embedded(true);
   }
