--- chrome/browser/ui/views/frame/browser_non_client_frame_view_factory_views.cc.orig	2019-03-15 06:37:06 UTC
+++ chrome/browser/ui/views/frame/browser_non_client_frame_view_factory_views.cc
@@ -13,7 +13,7 @@
 #include "chrome/browser/ui/views/frame/glass_browser_frame_view.h"
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
 #include "ui/views/linux_ui/linux_ui.h"
 #endif
 
