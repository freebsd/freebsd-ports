--- components/autofill/core/browser/autofill_optimization_guide.cc.orig	2024-10-16 21:31:09 UTC
+++ components/autofill/core/browser/autofill_optimization_guide.cc
@@ -186,7 +186,7 @@ void AutofillOptimizationGuide::OnDidParseForm(
     }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     if (has_credit_card_field &&
         !personal_data_manager->payments_data_manager()
              .GetServerCreditCards()
