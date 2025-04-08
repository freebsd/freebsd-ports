--- chrome/browser/regional_capabilities/regional_capabilities_service_client.h.orig	2025-03-24 20:50:14 UTC
+++ chrome/browser/regional_capabilities/regional_capabilities_service_client.h
@@ -21,7 +21,7 @@ class RegionalCapabilitiesServiceClient
 class RegionalCapabilitiesServiceClient
     : public RegionalCapabilitiesService::Client {
  public:
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   explicit RegionalCapabilitiesServiceClient(
       variations::VariationsService* variations_service);
 #else
@@ -35,7 +35,7 @@ class RegionalCapabilitiesServiceClient
   void FetchCountryId(CountryIdCallback country_id_fetched_callback) override;
 
  private:
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const int variations_country_id_;
 #endif
 };
