--- chrome/browser/ui/views/frame/browser_frame_view_linux.cc.orig	2025-01-27 17:37:37 UTC
+++ chrome/browser/ui/views/frame/browser_frame_view_linux.cc
@@ -70,7 +70,7 @@ void BrowserFrameViewLinux::PaintRestoredFrameBorder(
 
 void BrowserFrameViewLinux::PaintRestoredFrameBorder(
     gfx::Canvas* canvas) const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const bool tiled = frame()->tiled();
 #else
   const bool tiled = false;
@@ -125,7 +125,7 @@ float BrowserFrameViewLinux::GetRestoredCornerRadiusDi
 }
 
 float BrowserFrameViewLinux::GetRestoredCornerRadiusDip() const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const bool tiled = frame()->tiled();
 #else
   const bool tiled = false;
