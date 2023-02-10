--- chrome/updater/device_management/dm_client.cc.orig	2022-10-24 13:33:33 UTC
+++ chrome/updater/device_management/dm_client.cc
@@ -37,7 +37,7 @@
 #include "chrome/updater/win/net/network.h"
 #elif BUILDFLAG(IS_MAC)
 #include "chrome/updater/mac/net/network.h"
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/updater/linux/net/network.h"
 #endif
 
