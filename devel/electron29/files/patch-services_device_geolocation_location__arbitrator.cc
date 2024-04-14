--- services/device/geolocation/location_arbitrator.cc.orig	2024-02-21 00:20:51 UTC
+++ services/device/geolocation/location_arbitrator.cc
@@ -194,7 +194,7 @@ LocationArbitrator::NewSystemLocationProvider() {
 
 std::unique_ptr<LocationProvider>
 LocationArbitrator::NewSystemLocationProvider() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   return nullptr;
 #else
   return device::NewSystemLocationProvider(main_task_runner_,
