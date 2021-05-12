--- components/sync_device_info/local_device_info_util_linux.cc.orig	2021-04-14 01:08:47 UTC
+++ components/sync_device_info/local_device_info_util_linux.cc
@@ -38,8 +38,9 @@ std::string GetPersonalizableDeviceNameInternal() {
 #if BUILDFLAG(IS_CHROMEOS_ASH)
   return GetChromeOSDeviceNameFromType();
 #else
-  char hostname[HOST_NAME_MAX];
-  if (gethostname(hostname, HOST_NAME_MAX) == 0)  // Success.
+  int len = sysconf(_SC_HOST_NAME_MAX);
+  char hostname[len];
+  if (gethostname(hostname, _SC_HOST_NAME_MAX) == 0)  // Success.
     return hostname;
   return base::GetLinuxDistro();
 #endif
