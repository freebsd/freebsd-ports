--- chrome/browser/media/webrtc/webrtc_logging_controller.h.orig	2022-10-24 13:33:33 UTC
+++ chrome/browser/media/webrtc/webrtc_logging_controller.h
@@ -133,7 +133,7 @@ class WebRtcLoggingController
                          size_t web_app_id,
                          const StartEventLoggingCallback& callback);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Ensures that the WebRTC Logs directory exists and then grants render
   // process access to the 'WebRTC Logs' directory, and invokes |callback| with
   // the ids necessary to create a DirectoryEntry object.
@@ -192,7 +192,7 @@ class WebRtcLoggingController
       bool success,
       const std::string& error_message);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Grants the render process access to the 'WebRTC Logs' directory, and
   // invokes |callback| with the ids necessary to create a DirectoryEntry
   // object. If the |logs_path| couldn't be created or found, |error_callback|
