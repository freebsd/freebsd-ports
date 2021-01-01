--- chrome/browser/ssl/ssl_error_controller_client.cc.orig	2019-03-15 06:37:06 UTC
+++ chrome/browser/ssl/ssl_error_controller_client.cc
@@ -77,7 +77,7 @@ void LaunchDateAndTimeSettingsImpl() {
 #if defined(OS_ANDROID)
   chrome::android::OpenDateAndTimeSettings();
 
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   struct ClockCommand {
     const char* const pathname;
     const char* const argument;
@@ -219,7 +219,7 @@ void SSLErrorControllerClient::Proceed() {
 
 bool SSLErrorControllerClient::CanLaunchDateAndTimeSettings() {
 #if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_MACOSX) || \
-    defined(OS_WIN)
+    defined(OS_WIN) || defined(OS_BSD)
   return true;
 #else
   return false;
