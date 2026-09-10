--- electron/shell/browser/api/electron_api_power_monitor.h.orig	2026-05-08 13:54:01 UTC
+++ electron/shell/browser/api/electron_api_power_monitor.h
@@ -44,7 +44,7 @@ class PowerMonitor final : public gin::Wrappable<Power
   PowerMonitor& operator=(const PowerMonitor&) = delete;
 
  private:
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void SetListeningForShutdown(bool);
 #endif
 
