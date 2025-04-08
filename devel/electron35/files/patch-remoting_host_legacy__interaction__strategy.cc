--- remoting/host/legacy_interaction_strategy.cc.orig	2025-03-24 20:50:14 UTC
+++ remoting/host/legacy_interaction_strategy.cc
@@ -43,7 +43,7 @@
 #include "remoting/host/chromeos/mouse_cursor_monitor_aura.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "remoting/host/linux/wayland_utils.h"
 #endif
 
@@ -88,7 +88,7 @@ std::unique_ptr<DesktopCapturer> LegacyInteractionStra
   scoped_refptr<base::SingleThreadTaskRunner> capture_task_runner;
 #if BUILDFLAG(IS_CHROMEOS)
   capture_task_runner = ui_task_runner_;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (IsRunningWayland()) {
     // Each capturer instance should get its own thread so the capturers don't
     // compete with each other in multistream mode.
