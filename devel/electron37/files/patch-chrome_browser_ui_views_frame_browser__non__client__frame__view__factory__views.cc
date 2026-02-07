--- chrome/browser/ui/views/frame/browser_non_client_frame_view_factory_views.cc.orig	2025-06-30 07:04:30 UTC
+++ chrome/browser/ui/views/frame/browser_non_client_frame_view_factory_views.cc
@@ -15,7 +15,7 @@
 #include "chrome/browser/ui/views/frame/browser_frame_view_win.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/views/frame/browser_frame_view_layout_linux.h"
 #include "chrome/browser/ui/views/frame/browser_frame_view_layout_linux_native.h"
 #include "chrome/browser/ui/views/frame/browser_frame_view_linux_native.h"
@@ -33,7 +33,7 @@ std::unique_ptr<OpaqueBrowserFrameView> CreateOpaqueBr
 std::unique_ptr<OpaqueBrowserFrameView> CreateOpaqueBrowserFrameView(
     BrowserFrame* frame,
     BrowserView* browser_view) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto* profile = browser_view->browser()->profile();
   auto* linux_ui_theme = ui::LinuxUiTheme::GetForProfile(profile);
   auto* theme_service_factory = ThemeServiceFactory::GetForProfile(profile);
@@ -83,7 +83,7 @@ std::unique_ptr<BrowserNonClientFrameView> CreateBrows
     BrowserFrame* frame,
     BrowserView* browser_view) {
   if (browser_view->browser()->is_type_picture_in_picture()) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     return std::make_unique<PictureInPictureBrowserFrameViewLinux>(
         frame, browser_view);
 #else
