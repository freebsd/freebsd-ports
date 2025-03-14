--- components/search_engines/search_engine_choice/search_engine_choice_service.cc.orig	2025-01-27 17:37:37 UTC
+++ components/search_engines/search_engine_choice/search_engine_choice_service.cc
@@ -614,7 +614,7 @@ int SearchEngineChoiceService::GetCountryIdInternal() 
 
 int SearchEngineChoiceService::GetCountryIdInternal() {
   // `country_codes::kCountryIDAtInstall` may not be set yet.
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On Android, ChromeOS and Linux, `country_codes::kCountryIDAtInstall` is
   // computed asynchronously using platform-specific signals, and may not be
   // available yet.
