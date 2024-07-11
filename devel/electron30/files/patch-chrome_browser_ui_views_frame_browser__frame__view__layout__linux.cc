--- chrome/browser/ui/views/frame/browser_frame_view_layout_linux.cc.orig	2024-02-21 00:20:37 UTC
+++ chrome/browser/ui/views/frame/browser_frame_view_layout_linux.cc
@@ -53,7 +53,7 @@ gfx::Insets BrowserFrameViewLayoutLinux::RestoredFrame
         OpaqueBrowserFrameViewLayout::RestoredFrameBorderInsets());
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const bool tiled = delegate_->IsTiled();
 #else
   const bool tiled = false;
