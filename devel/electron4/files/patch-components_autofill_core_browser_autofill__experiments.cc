--- components/autofill/core/browser/autofill_experiments.cc.orig	2019-03-15 06:37:12 UTC
+++ components/autofill/core/browser/autofill_experiments.cc
@@ -109,7 +109,7 @@ bool IsAutofillCreditCardLocalCardMigrationExperimentE
 }
 
 bool OfferStoreUnmaskedCards() {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
   // The checkbox can be forced on with a flag, but by default we don't store
   // on Linux due to lack of system keychain integration. See crbug.com/162735
   return base::CommandLine::ForCurrentProcess()->HasSwitch(
@@ -212,7 +212,7 @@ bool IsMacViewsAutofillPopupExperimentEnabled() {
 #endif  // defined(OS_MACOSX)
 
 bool ShouldUseNativeViews() {
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   return base::FeatureList::IsEnabled(kAutofillExpandedPopupViews) ||
          base::FeatureList::IsEnabled(::features::kExperimentalUi);
 #else
