--- components/signin/public/identity_manager/account_capabilities.cc.orig	2026-04-28 21:06:17 UTC
+++ components/signin/public/identity_manager/account_capabilities.cc
@@ -145,7 +145,7 @@ signin::Tribool AccountCapabilities::can_sign_in_to_ch
 }
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 signin::Tribool AccountCapabilities::can_submit_feedback() const {
   return GetCapabilityByName(kCanSubmitFeedbackInChromeCapabilityName);
 }
