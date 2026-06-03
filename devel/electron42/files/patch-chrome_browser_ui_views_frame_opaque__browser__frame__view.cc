--- chrome/browser/ui/views/frame/opaque_browser_frame_view.cc.orig	2026-04-28 21:06:17 UTC
+++ chrome/browser/ui/views/frame/opaque_browser_frame_view.cc
@@ -58,7 +58,7 @@
 #include "ui/views/window/vector_icons/vector_icons.h"
 #include "ui/views/window/window_shape.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "ui/views/controls/menu/menu_runner.h"
 #endif
 
@@ -588,7 +588,7 @@ OpaqueBrowserFrameView::GetFrameButtonStyle() const {
 
 OpaqueBrowserFrameView::FrameButtonStyle
 OpaqueBrowserFrameView::GetFrameButtonStyle() const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return FrameButtonStyle::kMdButton;
 #else
   return FrameButtonStyle::kImageButton;
@@ -607,7 +607,7 @@ bool OpaqueBrowserFrameView::ShouldDrawRestoredFrameSh
   return false;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool OpaqueBrowserFrameView::IsTiled() const {
   return browser_widget()->tiled();
 }
@@ -848,7 +848,7 @@ void OpaqueBrowserFrameView::WindowIconPressed() {
 }
 
 void OpaqueBrowserFrameView::WindowIconPressed() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Chrome OS doesn't show the window icon, and Windows handles this on its own
   // due to the hit test being HTSYSMENU.
   menu_runner_ = std::make_unique<views::MenuRunner>(
