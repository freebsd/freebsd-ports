--- components/autofill/core/common/autofill_payments_features.cc.orig	2026-10-19 21:50:55 UTC
+++ components/autofill/core/common/autofill_payments_features.cc
@@ -38,7 +38,7 @@ BASE_FEATURE(kAutofillEnableAiBasedAmountExtraction,
 // page using server-side AI.
 BASE_FEATURE(kAutofillEnableAiBasedAmountExtraction,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD) 
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -54,7 +54,7 @@ BASE_FEATURE(kAutofillEnableAmountExtraction,
 // of the allowlisted merchant websites.
 BASE_FEATURE(kAutofillEnableAmountExtraction,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD) 
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -87,7 +87,7 @@ BASE_FEATURE(kAutofillEnableBuyNowPayLater,
 // When enabled, buy now pay later (BNPL) in Autofill will be offered.
 BASE_FEATURE(kAutofillEnableBuyNowPayLater,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD) 
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -98,7 +98,7 @@ BASE_FEATURE(kAutofillEnableBuyNowPayLaterForExternall
 // (BNPL) issuers that are externally linked.
 BASE_FEATURE(kAutofillEnableBuyNowPayLaterForExternallyLinked,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD) 
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -109,7 +109,7 @@ BASE_FEATURE(kAutofillEnableBuyNowPayLaterForKlarna,
 // offered.
 BASE_FEATURE(kAutofillEnableBuyNowPayLaterForKlarna,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD) 
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -119,7 +119,7 @@ BASE_FEATURE(kAutofillEnableBuyNowPayLaterSyncing,
 // When enabled, buy now pay later (BNPL) data will be synced to Chrome clients.
 BASE_FEATURE(kAutofillEnableBuyNowPayLaterSyncing,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD) 
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -130,7 +130,7 @@ BASE_FEATURE(kAutofillEnableBuyNowPayLaterUpdatedSugge
 // include the issuer names for better brand recognition.
 BASE_FEATURE(kAutofillEnableBuyNowPayLaterUpdatedSuggestionSecondLineString,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD) 
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -150,7 +150,7 @@ BASE_FEATURE(kAutofillEnableCardBenefitsForBmo,
 // UI.
 BASE_FEATURE(kAutofillEnableCardBenefitsForBmo,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD) 
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -195,7 +195,7 @@ BASE_FEATURE(kAutofillEnableFlatRateCardBenefitsFromCu
 // Payments Autofill UI.
 BASE_FEATURE(kAutofillEnableFlatRateCardBenefitsFromCurinos,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD) 
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -282,7 +282,7 @@ BASE_FEATURE(kAutofillEnableVcn3dsAuthentication,
 // the card, and FIDO is not.
 BASE_FEATURE(kAutofillEnableVcn3dsAuthentication,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD) 
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -350,7 +350,7 @@ BASE_FEATURE(kAutofillPreferBuyNowPayLaterBlocklists,
 // eligibility.
 BASE_FEATURE(kAutofillPreferBuyNowPayLaterBlocklists,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD) 
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -404,7 +404,7 @@ bool ShouldShowImprovedUserConsentForCreditCardSave() 
     "autofill_upstream_enforce_strike_delay_days", 1};
 
 bool ShouldShowImprovedUserConsentForCreditCardSave() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) 
   // The new user consent UI is fully launched on MacOS, Windows and Linux.
   return true;
 #else
