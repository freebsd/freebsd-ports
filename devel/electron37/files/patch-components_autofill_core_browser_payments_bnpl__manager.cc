--- components/autofill/core/browser/payments/bnpl_manager.cc.orig	2025-06-30 07:04:30 UTC
+++ components/autofill/core/browser/payments/bnpl_manager.cc
@@ -466,7 +466,7 @@ void BnplManager::MaybeUpdateSuggestionsWithBnpl(
       .OnBnplSuggestionShown();
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   payments_autofill_client().GetPaymentsDataManager().SetAutofillHasSeenBnpl();
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS)
