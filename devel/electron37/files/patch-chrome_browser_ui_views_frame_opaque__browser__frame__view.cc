--- chrome/browser/ui/views/frame/opaque_browser_frame_view.cc.orig	2025-03-24 20:50:14 UTC
+++ chrome/browser/ui/views/frame/opaque_browser_frame_view.cc
@@ -54,7 +54,7 @@
 #include "ui/views/window/vector_icons/vector_icons.h"
 #include "ui/views/window/window_shape.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "ui/views/controls/menu/menu_runner.h"
 #endif
 
@@ -572,7 +572,7 @@ OpaqueBrowserFrameView::GetFrameButtonStyle() const {
 
 OpaqueBrowserFrameView::FrameButtonStyle
 OpaqueBrowserFrameView::GetFrameButtonStyle() const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return FrameButtonStyle::kMdButton;
 #else
   return FrameButtonStyle::kImageButton;
@@ -591,7 +591,7 @@ bool OpaqueBrowserFrameView::ShouldDrawRestoredFrameSh
   return false;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool OpaqueBrowserFrameView::IsTiled() const {
   return frame()->tiled();
 }
@@ -794,7 +794,7 @@ void OpaqueBrowserFrameView::WindowIconPressed() {
 }
 
 void OpaqueBrowserFrameView::WindowIconPressed() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Chrome OS doesn't show the window icon, and Windows handles this on its own
   // due to the hit test being HTSYSMENU.
   menu_runner_ = std::make_unique<views::MenuRunner>(
