--- components/autofill/core/common/autofill_payments_features.cc.orig	2023-11-29 21:39:57 UTC
+++ components/autofill/core/common/autofill_payments_features.cc
@@ -261,7 +261,7 @@ bool ShouldShowImprovedUserConsentForCreditCardSave() 
 bool ShouldShowImprovedUserConsentForCreditCardSave() {
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
   // The new user consent UI is fully launched on MacOS, Windows and Linux.
   return true;
