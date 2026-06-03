--- remoting/base/constants.h.orig	2025-06-30 07:04:30 UTC
+++ remoting/base/constants.h
@@ -27,7 +27,7 @@ constexpr int kTargetFrameRate = 30;
 // The video frame rate.
 constexpr int kTargetFrameRate = 30;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 inline constexpr char kChromeRemoteDesktopSessionEnvVar[] =
     "CHROME_REMOTE_DESKTOP_SESSION";
 #endif
