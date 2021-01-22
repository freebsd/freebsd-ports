--- components/sync_device_info/local_device_info_util_linux.cc.orig	2020-05-26 07:48:21 UTC
+++ components/sync_device_info/local_device_info_util_linux.cc
@@ -37,8 +37,9 @@ std::string GetPersonalizableDeviceNameInternal() {
 #if defined(OS_CHROMEOS)
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
