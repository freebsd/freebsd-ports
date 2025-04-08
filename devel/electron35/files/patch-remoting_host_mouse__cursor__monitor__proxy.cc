--- remoting/host/mouse_cursor_monitor_proxy.cc.orig	2025-03-24 20:50:14 UTC
+++ remoting/host/mouse_cursor_monitor_proxy.cc
@@ -73,7 +73,7 @@ void MouseCursorMonitorProxy::Core::CreateMouseCursorM
 
 #if BUILDFLAG(IS_CHROMEOS)
   mouse_cursor_monitor_ = std::make_unique<MouseCursorMonitorAura>();
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (IsRunningWayland()) {
     mouse_cursor_monitor_ = webrtc::MouseCursorMonitor::Create(options);
   } else {
