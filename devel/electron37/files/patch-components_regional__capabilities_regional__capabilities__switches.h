--- components/regional_capabilities/regional_capabilities_switches.h.orig	2025-04-22 20:15:27 UTC
+++ components/regional_capabilities/regional_capabilities_switches.h
@@ -25,7 +25,7 @@ inline constexpr char kEeaListCountryOverride[] = "EEA
 inline constexpr char kDefaultListCountryOverride[] = "DEFAULT_EEA";
 inline constexpr char kEeaListCountryOverride[] = "EEA_ALL";
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // When an invalid `country_codes::CountryId` is stored in prefs and this
 // feature is enabled the pref will be cleared allowing a valid country to be
 // set again.
