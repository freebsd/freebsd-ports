--- chrome/browser/web_applications/components/web_app_protocol_handler_registration.cc.orig	2021-07-15 19:13:34 UTC
+++ chrome/browser/web_applications/components/web_app_protocol_handler_registration.cc
@@ -10,7 +10,7 @@
 
 namespace web_app {
 
-#if !(defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX))
+#if !(defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD))
 // Registers a protocol handler for the web app with the OS.
 void RegisterProtocolHandlersWithOs(
     const AppId& app_id,
