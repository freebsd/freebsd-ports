--- chrome/browser/ui/views/frame/browser_frame_view_linux.cc.orig	2026-01-07 00:52:53 UTC
+++ chrome/browser/ui/views/frame/browser_frame_view_linux.cc
@@ -71,7 +71,7 @@ void BrowserFrameViewLinux::PaintRestoredFrameBorder(
 
 void BrowserFrameViewLinux::PaintRestoredFrameBorder(
     gfx::Canvas* canvas) const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const bool tiled = browser_widget()->tiled();
 #else
   const bool tiled = false;
@@ -126,7 +126,7 @@ float BrowserFrameViewLinux::GetRestoredCornerRadiusDi
 }
 
 float BrowserFrameViewLinux::GetRestoredCornerRadiusDip() const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const bool tiled = browser_widget()->tiled();
 #else
   const bool tiled = false;
