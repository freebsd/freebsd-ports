--- chrome/browser/ui/views/frame/opaque_browser_frame_view.h.orig	2023-02-01 18:43:13 UTC
+++ chrome/browser/ui/views/frame/opaque_browser_frame_view.h
@@ -113,7 +113,7 @@ class OpaqueBrowserFrameView : public BrowserNonClient
       const gfx::Rect& bounding_rect) const override;
   bool IsTranslucentWindowOpacitySupported() const override;
   bool ShouldDrawRestoredFrameShadow() const override;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   ui::WindowTiledEdges GetTiledEdges() const override;
 #endif
 
@@ -229,7 +229,7 @@ class OpaqueBrowserFrameView : public BrowserNonClient
   // Background painter for the window frame.
   std::unique_ptr<views::FrameBackground> frame_background_;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::unique_ptr<views::MenuRunner> menu_runner_;
 #endif
 
