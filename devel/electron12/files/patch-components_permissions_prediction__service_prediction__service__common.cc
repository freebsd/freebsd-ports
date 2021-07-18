--- components/permissions/prediction_service/prediction_service_common.cc.orig	2021-04-14 01:08:46 UTC
+++ components/permissions/prediction_service/prediction_service_common.cc
@@ -11,7 +11,7 @@ namespace permissions {
 ClientFeatures_Platform GetCurrentPlatformProto() {
 #if defined(OS_WIN)
   return permissions::ClientFeatures_Platform_PLATFORM_WINDOWS;
-#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   return permissions::ClientFeatures_Platform_PLATFORM_LINUX;
 #elif defined(OS_ANDROID)
   return permissions::ClientFeatures_Platform_PLATFORM_ANDROID;
