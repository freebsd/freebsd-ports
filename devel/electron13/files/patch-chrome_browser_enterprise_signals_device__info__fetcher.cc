--- chrome/browser/enterprise/signals/device_info_fetcher.cc.orig	2021-07-15 19:13:33 UTC
+++ chrome/browser/enterprise/signals/device_info_fetcher.cc
@@ -12,6 +12,8 @@
 #include "chrome/browser/enterprise/signals/device_info_fetcher_win.h"
 #elif defined(OS_LINUX) || defined(OS_CHROMEOS)
 #include "chrome/browser/enterprise/signals/device_info_fetcher_linux.h"
+#elif defined(OS_FREEBSD)
+#include "chrome/browser/enterprise/signals/device_info_fetcher_freebsd.h"
 #endif
 
 namespace enterprise_signals {
@@ -60,6 +62,8 @@ std::unique_ptr<DeviceInfoFetcher> DeviceInfoFetcher::
   return std::make_unique<DeviceInfoFetcherWin>();
 #elif defined(OS_LINUX) || defined(OS_CHROMEOS)
   return std::make_unique<DeviceInfoFetcherLinux>();
+#elif defined(OS_FREEBSD)
+  return std::make_unique<DeviceInfoFetcherFreeBSD>();
 #else
   return std::make_unique<StubDeviceFetcher>();
 #endif
