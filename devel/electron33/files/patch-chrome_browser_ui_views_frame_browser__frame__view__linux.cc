--- chrome/browser/ui/views/frame/browser_frame_view_linux.cc.orig	2024-04-15 20:33:49 UTC
+++ chrome/browser/ui/views/frame/browser_frame_view_linux.cc
@@ -60,7 +60,7 @@ void BrowserFrameViewLinux::PaintRestoredFrameBorder(
 
 void BrowserFrameViewLinux::PaintRestoredFrameBorder(
     gfx::Canvas* canvas) const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const bool tiled = frame()->tiled();
 #else
   const bool tiled = false;
@@ -104,7 +104,7 @@ float BrowserFrameViewLinux::GetRestoredCornerRadiusDi
 }
 
 float BrowserFrameViewLinux::GetRestoredCornerRadiusDip() const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const bool tiled = frame()->tiled();
 #else
   const bool tiled = false;
