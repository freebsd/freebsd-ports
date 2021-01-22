--- services/device/geolocation/location_arbitrator.cc.orig	2020-05-26 08:03:25 UTC
+++ services/device/geolocation/location_arbitrator.cc
@@ -157,7 +157,7 @@ LocationArbitrator::NewNetworkLocationProvider(
 
 std::unique_ptr<LocationProvider>
 LocationArbitrator::NewSystemLocationProvider() {
-#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_FUCHSIA)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_FUCHSIA) || defined(OS_BSD)
   return nullptr;
 #else
   return device::NewSystemLocationProvider();
