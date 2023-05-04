--- electron/shell/browser/api/electron_api_power_monitor.h.orig	2023-01-24 16:58:16 UTC
+++ electron/shell/browser/api/electron_api_power_monitor.h
@@ -39,7 +39,7 @@ class PowerMonitor : public gin::Wrappable<PowerMonito
   explicit PowerMonitor(v8::Isolate* isolate);
   ~PowerMonitor() override;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void SetListeningForShutdown(bool);
 #endif
 
