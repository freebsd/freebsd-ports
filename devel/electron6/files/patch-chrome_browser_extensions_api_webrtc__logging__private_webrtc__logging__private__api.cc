--- chrome/browser/extensions/api/webrtc_logging_private/webrtc_logging_private_api.cc.orig	2019-09-10 11:13:39 UTC
+++ chrome/browser/extensions/api/webrtc_logging_private/webrtc_logging_private_api.cc
@@ -29,7 +29,7 @@
 #include "extensions/browser/process_manager.h"
 #include "extensions/common/error_utils.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "extensions/common/permissions/permissions_data.h"
 #endif
 
@@ -38,7 +38,7 @@ namespace {
 bool CanEnableAudioDebugRecordingsFromExtension(
     const extensions::Extension* extension) {
   bool enabled_by_permissions = false;
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   if (extension) {
     enabled_by_permissions =
         extension->permissions_data()->active_permissions().HasAPIPermission(
@@ -609,7 +609,7 @@ void WebrtcLoggingPrivateStartEventLoggingFunction::Fi
 }
 
 bool WebrtcLoggingPrivateGetLogsDirectoryFunction::RunAsync() {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Unlike other WebrtcLoggingPrivate functions that take a RequestInfo object,
   // this function shouldn't be called by a component extension on behalf of
   // some web code. It returns a DirectoryEntry for use directly in the calling
@@ -633,11 +633,11 @@ bool WebrtcLoggingPrivateGetLogsDirectoryFunction::Run
           &WebrtcLoggingPrivateGetLogsDirectoryFunction::FireErrorCallback,
           this));
   return true;
-#else   // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#else   // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   SetError("Not supported on the current OS");
   SendResponse(false);
   return false;
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 }
 
 void WebrtcLoggingPrivateGetLogsDirectoryFunction::FireCallback(
