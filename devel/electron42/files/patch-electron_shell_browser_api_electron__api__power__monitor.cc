--- electron/shell/browser/api/electron_api_power_monitor.cc.orig	2026-05-08 13:54:01 UTC
+++ electron/shell/browser/api/electron_api_power_monitor.cc
@@ -137,6 +137,11 @@ void PowerMonitor::OnSpeedLimitChange(int speed_limit)
       gin::DataObjectBuilder(isolate).Set("limit", speed_limit).Build());
 }
 
+#if BUILDFLAG(IS_BSD)
+void PowerMonitor::SetListeningForShutdown(bool is_listening) {
+}
+#endif
+
 #if BUILDFLAG(IS_LINUX)
 void PowerMonitor::SetListeningForShutdown(bool is_listening) {
   if (is_listening) {
@@ -160,7 +165,7 @@ gin::ObjectTemplateBuilder PowerMonitor::GetObjectTemp
   auto builder =
       gin_helper::EventEmitterMixin<PowerMonitor>::GetObjectTemplateBuilder(
           isolate);
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   builder.SetMethod("setListeningForShutdown",
                     &PowerMonitor::SetListeningForShutdown);
 #endif
