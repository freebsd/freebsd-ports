--- components/sync/device_info/local_device_info_provider_impl.cc.orig	2019-04-08 08:32:52 UTC
+++ components/sync/device_info/local_device_info_provider_impl.cc
@@ -15,7 +15,7 @@ namespace {
 sync_pb::SyncEnums::DeviceType GetLocalDeviceType(bool is_tablet) {
 #if defined(OS_CHROMEOS)
   return sync_pb::SyncEnums_DeviceType_TYPE_CROS;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return sync_pb::SyncEnums_DeviceType_TYPE_LINUX;
 #elif defined(OS_ANDROID) || defined(OS_IOS)
   return is_tablet ? sync_pb::SyncEnums_DeviceType_TYPE_TABLET
