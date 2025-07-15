--- chrome/browser/enterprise/signin/interstitials/managed_profile_required_page.cc.orig	2025-04-22 20:15:27 UTC
+++ chrome/browser/enterprise/signin/interstitials/managed_profile_required_page.cc
@@ -94,7 +94,7 @@ void ManagedProfileRequiredPage::CommandReceived(const
 
   switch (cmd) {
     case security_interstitials::CMD_DONT_PROCEED:
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       if (ManagedProfileRequiredNavigationThrottle::IsBlockingNavigations(
               web_contents()->GetBrowserContext())) {
         ManagedProfileRequiredNavigationThrottle::ShowBlockedWindow(
