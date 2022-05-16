--- electron/shell/browser/api/electron_api_power_monitor.cc.orig	2022-02-20 09:51:58 UTC
+++ electron/shell/browser/api/electron_api_power_monitor.cc
@@ -79,6 +79,11 @@ void PowerMonitor::OnResume() {
   Emit("resume");
 }
 
+#if defined(OS_BSD)
+void PowerMonitor::SetListeningForShutdown(bool is_listening) {
+}
+#endif
+
 #if defined(OS_LINUX)
 void PowerMonitor::SetListeningForShutdown(bool is_listening) {
   if (is_listening) {
@@ -105,7 +110,7 @@ gin::ObjectTemplateBuilder PowerMonitor::GetObjectTemp
   auto builder =
       gin_helper::EventEmitterMixin<PowerMonitor>::GetObjectTemplateBuilder(
           isolate);
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   builder.SetMethod("setListeningForShutdown",
                     &PowerMonitor::SetListeningForShutdown);
 #endif
