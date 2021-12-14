--- components/sync_device_info/local_device_info_util_linux.cc.orig	2021-07-15 19:13:38 UTC
+++ components/sync_device_info/local_device_info_util_linux.cc
@@ -38,8 +38,8 @@ std::string GetPersonalizableDeviceNameInternal() {
 #if BUILDFLAG(IS_CHROMEOS_ASH)
   return GetChromeOSDeviceNameFromType();
 #else
-  char hostname[HOST_NAME_MAX];
-  if (gethostname(hostname, HOST_NAME_MAX) == 0)  // Success.
+  char hostname[_POSIX_HOST_NAME_MAX];
+  if (gethostname(hostname, _POSIX_HOST_NAME_MAX) == 0)  // Success.
     return hostname;
   return base::GetLinuxDistro();
 #endif
