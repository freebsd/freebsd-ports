--- components/regional_capabilities/regional_capabilities_switches.h.orig	2025-08-26 20:49:50 UTC
+++ components/regional_capabilities/regional_capabilities_switches.h
@@ -33,7 +33,7 @@ BASE_DECLARE_FEATURE(kMitigateLegacySearchEnginePromoO
 BASE_DECLARE_FEATURE(kMitigateLegacySearchEnginePromoOverlap);
 #endif
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) 
 // Use finch permanent country instead of finch latest country for fetching
 // country ID.
 BASE_DECLARE_FEATURE(kUseFinchPermanentCountryForFetchCountryId);
