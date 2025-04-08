--- chrome/browser/media/webrtc/chrome_screen_enumerator.h.orig	2024-02-21 00:20:34 UTC
+++ chrome/browser/media/webrtc/chrome_screen_enumerator.h
@@ -20,7 +20,7 @@ class Window;
 class Window;
 }
 
-#elif BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 namespace webrtc {
 class DesktopCapturer;
 }
@@ -42,7 +42,7 @@ class ChromeScreenEnumerator : public media::ScreenEnu
 #if BUILDFLAG(IS_CHROMEOS_ASH)
   static void SetRootWindowsForTesting(
       std::vector<raw_ptr<aura::Window, VectorExperimental>> root_windows);
-#elif BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   static void SetDesktopCapturerForTesting(
       std::unique_ptr<webrtc::DesktopCapturer> capturer);
 #endif
