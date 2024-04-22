--- chrome/browser/supervised_user/supervised_user_navigation_observer.cc.orig	2023-08-10 01:48:36 UTC
+++ chrome/browser/supervised_user/supervised_user_navigation_observer.cc
@@ -44,7 +44,7 @@
 #include "chrome/browser/supervised_user/android/supervised_user_web_content_handler_impl.h"
 #elif BUILDFLAG(IS_CHROMEOS)
 #include "chrome/browser/supervised_user/chromeos/supervised_user_web_content_handler_impl.h"
-#elif BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#elif BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/supervised_user/linux_mac_windows/supervised_user_web_content_handler_impl.h"
 #endif
 
@@ -64,7 +64,7 @@ std::unique_ptr<supervised_user::WebContentHandler> Cr
 #elif BUILDFLAG(IS_ANDROID)
   return std::make_unique<SupervisedUserWebContentHandlerImpl>(
       web_contents, frame_id, navigation_id);
-#elif BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#elif BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   return std::make_unique<SupervisedUserWebContentHandlerImpl>(
       web_contents, frame_id, navigation_id);
 #endif
