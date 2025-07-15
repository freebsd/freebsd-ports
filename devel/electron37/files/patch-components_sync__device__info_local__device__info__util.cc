--- components/sync_device_info/local_device_info_util.cc.orig	2025-03-24 20:50:14 UTC
+++ components/sync_device_info/local_device_info_util.cc
@@ -84,7 +84,7 @@ sync_pb::SyncEnums::DeviceType GetLocalDeviceType() {
 sync_pb::SyncEnums::DeviceType GetLocalDeviceType() {
 #if BUILDFLAG(IS_CHROMEOS)
   return sync_pb::SyncEnums_DeviceType_TYPE_CROS;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return sync_pb::SyncEnums_DeviceType_TYPE_LINUX;
 #elif BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS)
   switch (ui::GetDeviceFormFactor()) {
@@ -107,7 +107,7 @@ DeviceInfo::OsType GetLocalDeviceOSType() {
 DeviceInfo::OsType GetLocalDeviceOSType() {
 #if BUILDFLAG(IS_CHROMEOS)
   return DeviceInfo::OsType::kChromeOsAsh;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return DeviceInfo::OsType::kLinux;
 #elif BUILDFLAG(IS_ANDROID)
   return DeviceInfo::OsType::kAndroid;
@@ -126,7 +126,7 @@ DeviceInfo::FormFactor GetLocalDeviceFormFactor() {
 
 DeviceInfo::FormFactor GetLocalDeviceFormFactor() {
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   return DeviceInfo::FormFactor::kDesktop;
 #elif BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS)
   return ui::GetDeviceFormFactor() == ui::DEVICE_FORM_FACTOR_TABLET
