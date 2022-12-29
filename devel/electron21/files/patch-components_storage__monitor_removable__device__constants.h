--- components/storage_monitor/removable_device_constants.h.orig	2022-02-28 16:54:41 UTC
+++ components/storage_monitor/removable_device_constants.h
@@ -14,7 +14,7 @@ namespace storage_monitor {
 extern const char kFSUniqueIdPrefix[];
 extern const char kVendorModelSerialPrefix[];
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 extern const char kVendorModelVolumeStoragePrefix[];
 #endif
 
