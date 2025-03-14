--- chrome/browser/supervised_user/supervised_user_navigation_throttle.h.orig	2025-01-27 17:37:37 UTC
+++ chrome/browser/supervised_user/supervised_user_navigation_throttle.h
@@ -22,7 +22,7 @@ namespace supervised_user {
 class Profile;
 
 namespace supervised_user {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 bool ShouldShowReAuthInterstitial(content::NavigationHandle& navigation_handle,
                                   bool is_main_frame);
 #endif
