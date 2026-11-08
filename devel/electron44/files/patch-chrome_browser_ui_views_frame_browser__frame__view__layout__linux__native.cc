--- chrome/browser/ui/views/frame/browser_frame_view_layout_linux_native.cc.orig	2026-06-23 23:37:18 UTC
+++ chrome/browser/ui/views/frame/browser_frame_view_layout_linux_native.cc
@@ -19,7 +19,7 @@ ui::WindowFrameProvider* BrowserFrameViewLayoutLinuxNa
 
 ui::WindowFrameProvider* BrowserFrameViewLayoutLinuxNative::GetFrameProvider()
     const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const bool tiled = delegate_->IsTiled();
   const bool maximized = delegate_->IsMaximized();
 #else
