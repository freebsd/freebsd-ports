--- components/autofill/core/common/autofill_payments_features.cc.orig	2025-08-26 20:49:50 UTC
+++ components/autofill/core/common/autofill_payments_features.cc
@@ -345,7 +345,7 @@ bool ShouldShowImprovedUserConsentForCreditCardSave() 
              base::FEATURE_DISABLED_BY_DEFAULT);
 
 bool ShouldShowImprovedUserConsentForCreditCardSave() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // The new user consent UI is fully launched on MacOS, Windows and Linux.
   return true;
 #else
