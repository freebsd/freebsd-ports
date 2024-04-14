--- chrome/browser/ui/views/frame/browser_frame_view_linux.cc.orig	2024-02-21 00:20:37 UTC
+++ chrome/browser/ui/views/frame/browser_frame_view_linux.cc
@@ -77,7 +77,7 @@ void BrowserFrameViewLinux::PaintRestoredFrameBorder(
 
 void BrowserFrameViewLinux::PaintRestoredFrameBorder(
     gfx::Canvas* canvas) const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const bool tiled = frame()->tiled();
 #else
   const bool tiled = false;
@@ -103,7 +103,7 @@ float BrowserFrameViewLinux::GetRestoredCornerRadiusDi
 }
 
 float BrowserFrameViewLinux::GetRestoredCornerRadiusDip() const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const bool tiled = frame()->tiled();
 #else
   const bool tiled = false;
