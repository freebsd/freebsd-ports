--- chrome/browser/media/webrtc/webrtc_logging_controller.cc.orig	2023-05-25 00:41:43 UTC
+++ chrome/browser/media/webrtc/webrtc_logging_controller.cc
@@ -25,10 +25,10 @@
 #include "components/webrtc_logging/browser/text_log_list.h"
 #include "content/public/browser/render_process_host.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "content/public/browser/child_process_security_policy.h"
 #include "storage/browser/file_system/isolated_context.h"
-#endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 
 using webrtc_event_logging::WebRtcEventLogManager;
 
@@ -284,7 +284,7 @@ void WebRtcLoggingController::StartEventLogging(
       web_app_id, callback);
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void WebRtcLoggingController::GetLogsDirectory(
     LogsDirectoryCallback callback,
     LogsDirectoryErrorCallback error_callback) {
@@ -329,7 +329,7 @@ void WebRtcLoggingController::GrantLogsDirectoryAccess
       FROM_HERE,
       base::BindOnce(std::move(callback), file_system.id(), registered_name));
 }
-#endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 
 void WebRtcLoggingController::OnRtpPacket(
     std::unique_ptr<uint8_t[]> packet_header,
