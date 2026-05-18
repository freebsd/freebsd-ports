--- components/trusted_vault/trusted_vault_connection_impl.cc.orig	2025-06-30 07:04:30 UTC
+++ components/trusted_vault/trusted_vault_connection_impl.cc
@@ -105,7 +105,7 @@ GetLocalPhysicalDeviceType() {
   // currently used or even built on all platforms.
 #if BUILDFLAG(IS_CHROMEOS)
   return trusted_vault_pb::PhysicalDeviceMetadata::DEVICE_TYPE_CHROMEOS;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return trusted_vault_pb::PhysicalDeviceMetadata::DEVICE_TYPE_LINUX;
 #elif BUILDFLAG(IS_ANDROID)
   return trusted_vault_pb::PhysicalDeviceMetadata::DEVICE_TYPE_ANDROID;
