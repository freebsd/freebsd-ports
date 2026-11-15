--- components/sync_device_info/local_device_info_util.cc.orig	2026-08-24 20:59:34 UTC
+++ components/sync_device_info/local_device_info_util.cc
@@ -91,7 +91,7 @@ DeviceInfo::DeviceType GetLocalDeviceType() {
 DeviceInfo::DeviceType GetLocalDeviceType() {
 #if BUILDFLAG(IS_CHROMEOS)
   return DeviceInfo::DeviceType::kChromeOS;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return DeviceInfo::DeviceType::kLinux;
 #elif BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS)
   switch (ui::GetDeviceFormFactor()) {
@@ -114,7 +114,7 @@ DeviceInfo::OsType GetLocalDeviceOSType() {
 DeviceInfo::OsType GetLocalDeviceOSType() {
 #if BUILDFLAG(IS_CHROMEOS)
   return DeviceInfo::OsType::kChromeOsAsh;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return DeviceInfo::OsType::kLinux;
 #elif BUILDFLAG(IS_ANDROID)
   return DeviceInfo::OsType::kAndroid;
