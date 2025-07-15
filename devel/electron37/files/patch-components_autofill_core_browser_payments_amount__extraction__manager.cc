--- components/autofill/core/browser/payments/amount_extraction_manager.cc.orig	2025-06-30 07:04:30 UTC
+++ components/autofill/core/browser/payments/amount_extraction_manager.cc
@@ -109,7 +109,7 @@ AmountExtractionManager::GetEligibleFeatures(const Sug
   }
 
   if constexpr (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
-                BUILDFLAG(IS_CHROMEOS)) {
+                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) {
     if (base::FeatureList::IsEnabled(
             ::autofill::features::
                 kAutofillEnableAmountExtractionDesktopLogging)) {
@@ -188,7 +188,7 @@ void AmountExtractionManager::OnCheckoutAmountReceived
     bnpl_manager->OnAmountExtractionReturned(parsed_extracted_amount);
   }
   if constexpr (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
-                BUILDFLAG(IS_CHROMEOS)) {
+                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) {
     if (base::FeatureList::IsEnabled(
             ::autofill::features::
                 kAutofillEnableAmountExtractionDesktopLogging)) {
@@ -212,7 +212,7 @@ void AmountExtractionManager::OnTimeoutReached() {
       autofill_metrics::AmountExtractionResult::kTimeout);
   // TODO(crbug.com/378517983): Add BNPL flow action logic here.
   if constexpr (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
-                BUILDFLAG(IS_CHROMEOS)) {
+                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) {
     if (base::FeatureList::IsEnabled(
             ::autofill::features::
                 kAutofillEnableAmountExtractionDesktopLogging)) {
@@ -232,7 +232,7 @@ AmountExtractionManager::CheckEligiblilityForFeaturesR
   // Check eligibility of BNPL feature.
   // Currently, BNPL is only offered for desktop platforms.
   if constexpr (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
-                BUILDFLAG(IS_CHROMEOS)) {
+                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) {
     if (BnplManager* bnpl_manager = autofill_manager_->GetPaymentsBnplManager();
         bnpl_manager && bnpl_manager->IsEligibleForBnpl()) {
       eligible_features.insert(EligibleFeature::kBnpl);
