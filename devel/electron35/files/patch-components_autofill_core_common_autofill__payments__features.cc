--- components/autofill/core/common/autofill_payments_features.cc.orig	2025-03-24 20:50:14 UTC
+++ components/autofill/core/common/autofill_payments_features.cc
@@ -292,7 +292,7 @@ bool ShouldShowImprovedUserConsentForCreditCardSave() 
 #endif  // BUILDFLAG(IS_ANDROID)
 
 bool ShouldShowImprovedUserConsentForCreditCardSave() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // The new user consent UI is fully launched on MacOS, Windows and Linux.
   return true;
 #else
