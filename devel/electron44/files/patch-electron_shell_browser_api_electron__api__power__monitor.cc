--- electron/shell/browser/api/electron_api_power_monitor.cc.orig	2026-09-29 23:27:57 UTC
+++ electron/shell/browser/api/electron_api_power_monitor.cc
@@ -131,6 +131,11 @@ void PowerMonitor::OnSpeedLimitChange(int speed_limit)
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
@@ -154,7 +159,7 @@ gin::ObjectTemplateBuilder PowerMonitor::GetObjectTemp
   auto builder =
       gin_helper::EventEmitterMixin<PowerMonitor>::GetObjectTemplateBuilder(
           isolate);
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   builder.SetMethod("setListeningForShutdown",
                     &PowerMonitor::SetListeningForShutdown);
 #endif
