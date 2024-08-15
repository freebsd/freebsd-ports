--- components/supervised_user/core/browser/supervised_user_service.cc.orig	2024-06-18 21:43:30 UTC
+++ components/supervised_user/core/browser/supervised_user_service.cc
@@ -175,7 +175,7 @@ FirstTimeInterstitialBannerState SupervisedUserService
     const FirstTimeInterstitialBannerState original_state) {
   FirstTimeInterstitialBannerState target_state = original_state;
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
   if (original_state != FirstTimeInterstitialBannerState::kSetupComplete &&
       can_show_first_time_interstitial_banner_) {
     target_state = FirstTimeInterstitialBannerState::kNeedToShow;
