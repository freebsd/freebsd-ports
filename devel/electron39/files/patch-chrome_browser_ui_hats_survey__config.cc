--- chrome/browser/ui/hats/survey_config.cc.orig	2025-10-21 20:19:54 UTC
+++ chrome/browser/ui/hats/survey_config.cc
@@ -166,7 +166,7 @@ constexpr char kHatsSurveyOrganicTriggerSafetyHubAndro
     "safety_hub_android_organic_survey";
 #endif  // #if !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr char kHatsSurveyTriggerPrivacySandboxWhatsNewSurvey[] =
     "privacy-sandbox-whats-new-survey";
 #endif  // !BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
@@ -505,7 +505,7 @@ std::vector<hats::SurveyConfig> GetAllSurveyConfigs() 
       &features::kHappinessTrackingSurveysForWallpaperSearch,
       kHatsSurveyTriggerWallpaperSearch);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::vector<std::string> identity_string_psd_fields{
       "Channel", "Chrome Version", "Number of Chrome Profiles",
       "Number of Google Accounts", "Sign-in Status"};
