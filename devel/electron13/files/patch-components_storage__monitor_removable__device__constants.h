--- components/storage_monitor/removable_device_constants.h.orig	2021-07-15 19:13:38 UTC
+++ components/storage_monitor/removable_device_constants.h
@@ -16,7 +16,7 @@ namespace storage_monitor {
 extern const char kFSUniqueIdPrefix[];
 extern const char kVendorModelSerialPrefix[];
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 extern const char kVendorModelVolumeStoragePrefix[];
 #endif
 
