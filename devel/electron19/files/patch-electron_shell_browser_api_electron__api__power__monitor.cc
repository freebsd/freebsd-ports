--- electron/shell/browser/api/electron_api_power_monitor.cc.orig	2022-05-18 15:31:32 UTC
+++ electron/shell/browser/api/electron_api_power_monitor.cc
@@ -79,6 +79,11 @@ void PowerMonitor::OnResume() {
   Emit("resume");
 }
 
+#if BUILDFLAG(IS_BSD)
+void PowerMonitor::SetListeningForShutdown(bool is_listening) {
+}
+#endif
+
 #if BUILDFLAG(IS_LINUX)
 void PowerMonitor::SetListeningForShutdown(bool is_listening) {
   if (is_listening) {
@@ -105,7 +110,7 @@ gin::ObjectTemplateBuilder PowerMonitor::GetObjectTemp
   auto builder =
       gin_helper::EventEmitterMixin<PowerMonitor>::GetObjectTemplateBuilder(
           isolate);
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   builder.SetMethod("setListeningForShutdown",
                     &PowerMonitor::SetListeningForShutdown);
 #endif
