--- chrome/browser/ui/views/frame/browser_non_client_frame_view_factory_views.cc.orig	2019-09-10 10:42:31 UTC
+++ chrome/browser/ui/views/frame/browser_non_client_frame_view_factory_views.cc
@@ -13,7 +13,7 @@
 #include "chrome/browser/ui/views/frame/glass_browser_frame_view.h"
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
 #include "ui/views/linux_ui/linux_ui.h"
 #endif
 
@@ -32,7 +32,7 @@ OpaqueBrowserFrameView* CreateOpaqueBrowserFrameView(
     BrowserView* browser_view) {
 #if BUILDFLAG(ENABLE_NATIVE_WINDOW_NAV_BUTTONS)
   std::unique_ptr<views::NavButtonProvider> nav_button_provider;
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   if (ThemeServiceFactory::GetForProfile(browser_view->browser()->profile())
           ->UsingSystemTheme() &&
       views::LinuxUI::instance()) {
