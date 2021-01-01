--- chrome/browser/ui/views/frame/browser_frame.cc.orig	2019-03-15 06:37:06 UTC
+++ chrome/browser/ui/views/frame/browser_frame.cc
@@ -36,7 +36,7 @@
 #include "components/user_manager/user_manager.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "chrome/browser/ui/views/frame/browser_command_handler_linux.h"
 #endif
 
@@ -90,7 +90,7 @@ void BrowserFrame::InitBrowserFrame() {
     non_client_view()->set_context_menu_controller(this);
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   browser_command_handler_.reset(new BrowserCommandHandlerLinux(browser_view_));
 #endif
 }
