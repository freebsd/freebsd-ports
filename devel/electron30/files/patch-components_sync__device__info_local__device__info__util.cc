--- components/sync_device_info/local_device_info_util.cc.orig	2023-10-19 19:58:20 UTC
+++ components/sync_device_info/local_device_info_util.cc
@@ -82,7 +82,7 @@ void OnMachineStatisticsLoaded(LocalDeviceNameInfo* na
 sync_pb::SyncEnums::DeviceType GetLocalDeviceType() {
 #if BUILDFLAG(IS_CHROMEOS)
   return sync_pb::SyncEnums_DeviceType_TYPE_CROS;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return sync_pb::SyncEnums_DeviceType_TYPE_LINUX;
 #elif BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS)
   switch (ui::GetDeviceFormFactor()) {
@@ -107,7 +107,7 @@ DeviceInfo::OsType GetLocalDeviceOSType() {
   return DeviceInfo::OsType::kChromeOsAsh;
 #elif BUILDFLAG(IS_CHROMEOS_LACROS)
   return DeviceInfo::OsType::kChromeOsLacros;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return DeviceInfo::OsType::kLinux;
 #elif BUILDFLAG(IS_ANDROID)
   return DeviceInfo::OsType::kAndroid;
@@ -126,7 +126,7 @@ DeviceInfo::OsType GetLocalDeviceOSType() {
 
 DeviceInfo::FormFactor GetLocalDeviceFormFactor() {
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   return DeviceInfo::FormFactor::kDesktop;
 #elif BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS)
   return ui::GetDeviceFormFactor() == ui::DEVICE_FORM_FACTOR_TABLET
