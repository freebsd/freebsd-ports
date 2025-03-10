--- chrome/browser/supervised_user/supervised_user_google_auth_navigation_throttle.cc.orig	2024-11-09 21:36:37 UTC
+++ chrome/browser/supervised_user/supervised_user_google_auth_navigation_throttle.cc
@@ -31,7 +31,7 @@
 #include "chrome/browser/supervised_user/child_accounts/child_account_service_android.h"
 #include "components/signin/public/identity_manager/identity_manager.h"
 #include "ui/android/view_android.h"
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/supervised_user/supervised_user_verification_controller_client.h"
 #include "chrome/browser/supervised_user/supervised_user_verification_page.h"
 #endif
@@ -147,7 +147,7 @@ SupervisedUserGoogleAuthNavigationThrottle::ShouldProc
     return content::NavigationThrottle::DEFER;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // When an unauthenticated supervised user tries to access YouTube, we force
   // re-authentication with an interstitial so that YouTube can be subject to
   // content restrictions. This interstitial is only available on Desktop
