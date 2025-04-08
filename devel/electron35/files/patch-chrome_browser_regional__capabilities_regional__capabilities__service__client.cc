--- chrome/browser/regional_capabilities/regional_capabilities_service_client.cc.orig	2025-03-24 20:50:14 UTC
+++ chrome/browser/regional_capabilities/regional_capabilities_service_client.cc
@@ -8,7 +8,7 @@
 #include "base/strings/string_util.h"
 #include "components/country_codes/country_codes.h"
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "components/variations/service/variations_service.h"
 #endif
 
@@ -20,7 +20,7 @@ namespace regional_capabilities {
 #endif
 
 namespace regional_capabilities {
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 RegionalCapabilitiesServiceClient::RegionalCapabilitiesServiceClient(
     variations::VariationsService* variations_service)
@@ -56,7 +56,7 @@ void RegionalCapabilitiesServiceClient::FetchCountryId
       base::android::AttachCurrentThread(),
       reinterpret_cast<intptr_t>(heap_callback.release()));
 }
-#elif BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void RegionalCapabilitiesServiceClient::FetchCountryId(
     CountryIdCallback on_country_id_fetched) {
   std::move(on_country_id_fetched).Run(variations_country_id_);
