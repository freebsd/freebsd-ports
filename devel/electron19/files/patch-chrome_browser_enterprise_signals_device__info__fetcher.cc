--- chrome/browser/enterprise/signals/device_info_fetcher.cc.orig	2022-05-19 03:45:17 UTC
+++ chrome/browser/enterprise/signals/device_info_fetcher.cc
@@ -10,7 +10,7 @@
 #include "chrome/browser/enterprise/signals/device_info_fetcher_mac.h"
 #elif BUILDFLAG(IS_WIN)
 #include "chrome/browser/enterprise/signals/device_info_fetcher_win.h"
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/signals/device_info_fetcher_linux.h"
 #endif
 
@@ -70,7 +70,7 @@ std::unique_ptr<DeviceInfoFetcher> DeviceInfoFetcher::
   return std::make_unique<DeviceInfoFetcherMac>();
 #elif BUILDFLAG(IS_WIN)
   return std::make_unique<DeviceInfoFetcherWin>();
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return std::make_unique<DeviceInfoFetcherLinux>();
 #else
   return std::make_unique<StubDeviceFetcher>();
