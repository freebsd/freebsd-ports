--- electron/shell/browser/api/electron_api_power_monitor.h.orig	2023-05-03 13:27:52 UTC
+++ electron/shell/browser/api/electron_api_power_monitor.h
@@ -40,7 +40,7 @@ class PowerMonitor : public gin::Wrappable<PowerMonito
   explicit PowerMonitor(v8::Isolate* isolate);
   ~PowerMonitor() override;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void SetListeningForShutdown(bool);
 #endif
 
