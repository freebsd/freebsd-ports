--- third_party/blink/renderer/core/origin_trials/origin_trial_context.cc.orig	2025-01-27 17:37:37 UTC
+++ third_party/blink/renderer/core/origin_trials/origin_trial_context.cc
@@ -551,7 +551,7 @@ bool OriginTrialContext::CanEnableTrialFromName(const 
   }
 
   if (trial_name == "TranslationAPI") {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     return base::FeatureList::IsEnabled(features::kEnableTranslationAPI);
 #else
     return false;
