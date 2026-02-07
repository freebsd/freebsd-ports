--- components/storage_monitor/removable_device_constants.h.orig	2025-04-22 20:15:27 UTC
+++ components/storage_monitor/removable_device_constants.h
@@ -15,7 +15,7 @@ extern COMPONENT_EXPORT(STORAGE_MONITOR) const char kV
 extern COMPONENT_EXPORT(STORAGE_MONITOR) const char kFSUniqueIdPrefix[];
 extern COMPONENT_EXPORT(STORAGE_MONITOR) const char kVendorModelSerialPrefix[];
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 extern COMPONENT_EXPORT(STORAGE_MONITOR) const
     char kVendorModelVolumeStoragePrefix[];
 #endif
