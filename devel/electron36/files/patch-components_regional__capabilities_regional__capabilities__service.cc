--- components/regional_capabilities/regional_capabilities_service.cc.orig	2025-04-22 20:15:27 UTC
+++ components/regional_capabilities/regional_capabilities_service.cc
@@ -216,7 +216,7 @@ std::optional<CountryId> RegionalCapabilitiesService::
     return persisted_country_id;
   }
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(switches::kClearPrefForUnknownCountry)) {
     profile_prefs_->ClearPref(country_codes::kCountryIDAtInstall);
     base::UmaHistogramEnumeration(kUnknownCountryIdStored,
