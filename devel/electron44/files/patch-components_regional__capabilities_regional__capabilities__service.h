--- components/regional_capabilities/regional_capabilities_service.h.orig	2026-06-23 23:37:18 UTC
+++ components/regional_capabilities/regional_capabilities_service.h
@@ -123,7 +123,7 @@ class RegionalCapabilitiesService : public KeyedServic
   static bool IsInAnySearchEngineChoiceScreenRegion(
       const country_codes::CountryId& tested_country_id);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Returns whether the country obtained from the client is associated with
   // a region in which we can show a search engine choice screen.
   //
