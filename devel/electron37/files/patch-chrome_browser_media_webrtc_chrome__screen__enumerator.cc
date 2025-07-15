--- chrome/browser/media/webrtc/chrome_screen_enumerator.cc.orig	2025-04-22 20:15:27 UTC
+++ chrome/browser/media/webrtc/chrome_screen_enumerator.cc
@@ -21,7 +21,7 @@
 #if BUILDFLAG(IS_CHROMEOS)
 #include "ash/shell.h"
 #include "ui/aura/window.h"
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/functional/callback.h"
 #include "content/public/browser/desktop_capture.h"
 #endif
@@ -32,7 +32,7 @@ base::LazyInstance<std::vector<raw_ptr<aura::Window, V
     DestructorAtExit root_windows_for_testing_ = LAZY_INSTANCE_INITIALIZER;
 }  // namespace
 
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 namespace {
 base::LazyInstance<std::unique_ptr<webrtc::DesktopCapturer>>::DestructorAtExit
     g_desktop_capturer_for_testing = LAZY_INSTANCE_INITIALIZER;
@@ -79,7 +79,7 @@ blink::mojom::StreamDevicesSetPtr EnumerateScreens(
   return stream_devices_set;
 }
 
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 blink::mojom::StreamDevicesSetPtr EnumerateScreens(
     blink::mojom::MediaStreamType stream_type) {
   DCHECK_CURRENTLY_ON(content::BrowserThread::UI);
@@ -130,7 +130,7 @@ void ChromeScreenEnumerator::SetRootWindowsForTesting(
   root_windows_for_testing_.Get() = std::move(root_windows);
 }
 
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void ChromeScreenEnumerator::SetDesktopCapturerForTesting(
     std::unique_ptr<webrtc::DesktopCapturer> capturer) {
   g_desktop_capturer_for_testing.Get() = std::move(capturer);
@@ -143,7 +143,7 @@ void ChromeScreenEnumerator::EnumerateScreens(
     ScreensCallback screens_callback) const {
   DCHECK_CURRENTLY_ON(content::BrowserThread::IO);
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   content::GetUIThreadTaskRunner({})->PostTaskAndReplyWithResult(
       FROM_HERE, base::BindOnce(::EnumerateScreens, stream_type),
       base::BindOnce(
