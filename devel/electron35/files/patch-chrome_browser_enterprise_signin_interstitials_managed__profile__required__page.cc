--- chrome/browser/enterprise/signin/interstitials/managed_profile_required_page.cc.orig	2025-03-24 20:50:14 UTC
+++ chrome/browser/enterprise/signin/interstitials/managed_profile_required_page.cc
@@ -92,7 +92,7 @@ void ManagedProfileRequiredPage::CommandReceived(const
 
   switch (cmd) {
     case security_interstitials::CMD_DONT_PROCEED:
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       if (ManagedProfileRequiredNavigationThrottle::IsBlockingNavigations(
               web_contents()->GetBrowserContext())) {
         ManagedProfileRequiredNavigationThrottle::ShowBlockedWindow(
