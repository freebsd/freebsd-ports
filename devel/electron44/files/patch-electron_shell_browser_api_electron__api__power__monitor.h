--- electron/shell/browser/api/electron_api_power_monitor.h.orig	2026-09-29 23:27:57 UTC
+++ electron/shell/browser/api/electron_api_power_monitor.h
@@ -56,7 +56,7 @@ class PowerMonitor final : public gin::Wrappable<Power
   PowerMonitor& operator=(const PowerMonitor&) = delete;
 
  private:
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void SetListeningForShutdown(bool);
 #endif
 
