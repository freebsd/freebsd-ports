--- chrome/browser/ui/views/frame/browser_frame_view_layout_linux_native.cc.orig	2025-04-22 20:15:27 UTC
+++ chrome/browser/ui/views/frame/browser_frame_view_layout_linux_native.cc
@@ -18,7 +18,7 @@ ui::WindowFrameProvider* BrowserFrameViewLayoutLinuxNa
 
 ui::WindowFrameProvider* BrowserFrameViewLayoutLinuxNative::GetFrameProvider()
     const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const bool tiled = delegate_->IsTiled();
   const bool maximized = delegate_->IsMaximized();
 #else
