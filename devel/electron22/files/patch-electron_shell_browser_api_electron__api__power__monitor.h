--- electron/shell/browser/api/electron_api_power_monitor.h.orig	2022-05-18 15:31:32 UTC
+++ electron/shell/browser/api/electron_api_power_monitor.h
@@ -41,7 +41,7 @@ class PowerMonitor : public gin::Wrappable<PowerMonito
   explicit PowerMonitor(v8::Isolate* isolate);
   ~PowerMonitor() override;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void SetListeningForShutdown(bool);
 #endif
 
