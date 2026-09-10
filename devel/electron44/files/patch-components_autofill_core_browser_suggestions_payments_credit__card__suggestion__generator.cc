--- components/autofill/core/browser/suggestions/payments/credit_card_suggestion_generator.cc.orig	2026-08-24 20:59:34 UTC
+++ components/autofill/core/browser/suggestions/payments/credit_card_suggestion_generator.cc
@@ -211,7 +211,7 @@ bool IsSaveAndFillEnabled() {
 
 bool IsSaveAndFillEnabled() {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return base::FeatureList::IsEnabled(features::kAutofillEnableSaveAndFill);
 #elif BUILDFLAG(IS_IOS)
   return base::FeatureList::IsEnabled(
