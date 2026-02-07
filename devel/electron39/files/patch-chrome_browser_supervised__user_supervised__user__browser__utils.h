--- chrome/browser/supervised_user/supervised_user_browser_utils.h.orig	2025-01-27 17:37:37 UTC
+++ chrome/browser/supervised_user/supervised_user_browser_utils.h
@@ -52,7 +52,7 @@ void AssertChildStatusOfTheUser(Profile* profile, bool
 // of the user.
 void AssertChildStatusOfTheUser(Profile* profile, bool is_child);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 // Returns the html content of the reauthentication interstitial for blocked
 // sites. This interstitial is associated with the given NavigationHandle.
 std::string CreateReauthenticationInterstitialForBlockedSites(
