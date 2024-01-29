--- chrome/renderer/chrome_render_frame_observer.cc.orig	2023-10-19 19:58:08 UTC
+++ chrome/renderer/chrome_render_frame_observer.cc
@@ -349,7 +349,7 @@ void ChromeRenderFrameObserver::OnDestruct() {
 
 void ChromeRenderFrameObserver::DraggableRegionsChanged() {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Only the main frame is allowed to control draggable regions, to avoid other
   // frames manipulate the regions in the browser process.
   if (!render_frame()->IsMainFrame())
