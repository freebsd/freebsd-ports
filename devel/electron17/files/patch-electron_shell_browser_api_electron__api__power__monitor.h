--- electron/shell/browser/api/electron_api_power_monitor.h.orig	2022-05-11 15:32:29 UTC
+++ electron/shell/browser/api/electron_api_power_monitor.h
@@ -41,7 +41,7 @@ class PowerMonitor : public gin::Wrappable<PowerMonito
   explicit PowerMonitor(v8::Isolate* isolate);
   ~PowerMonitor() override;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   void SetListeningForShutdown(bool);
 #endif
 
