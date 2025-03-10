--- chrome/browser/supervised_user/supervised_user_navigation_throttle.cc.orig	2024-10-16 21:31:01 UTC
+++ chrome/browser/supervised_user/supervised_user_navigation_throttle.cc
@@ -201,7 +201,7 @@ void SupervisedUserNavigationThrottle::OnCheckDone(
   }
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 SupervisedUserVerificationPage::VerificationPurpose
 GetVerificationPurposeFromFilteringReason(
     supervised_user::FilteringBehaviorReason reason) {
@@ -235,7 +235,7 @@ void SupervisedUserNavigationThrottle::OnInterstitialR
       Profile* profile = Profile::FromBrowserContext(
           navigation_handle()->GetWebContents()->GetBrowserContext());
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
       supervised_user::ChildAccountService* child_account_service =
           ChildAccountServiceFactory::GetForProfile(profile);
       if (base::FeatureList::IsEnabled(
