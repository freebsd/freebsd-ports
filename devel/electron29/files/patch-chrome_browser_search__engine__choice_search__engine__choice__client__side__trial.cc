--- chrome/browser/search_engine_choice/search_engine_choice_client_side_trial.cc.orig	2024-02-21 00:20:35 UTC
+++ chrome/browser/search_engine_choice/search_engine_choice_client_side_trial.cc
@@ -132,7 +132,7 @@ void SetUpIfNeeded(const base::FieldTrial::EntropyProv
 void SetUpIfNeeded(const base::FieldTrial::EntropyProvider& entropy_provider,
                    base::FeatureList* feature_list,
                    PrefService* local_state) {
-#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_MAC)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_BSD)
   // Platform not in scope for this client-side trial.
   return;
 #else
