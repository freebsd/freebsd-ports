--- chrome/browser/media/router/discovery/discovery_network_list_wifi_linux.cc.orig	2025-03-24 20:50:14 UTC
+++ chrome/browser/media/router/discovery/discovery_network_list_wifi_linux.cc
@@ -9,7 +9,11 @@
 
 #include "chrome/browser/media/router/discovery/discovery_network_list_wifi.h"
 
+#include "build/build_config.h"
+
+#if !BUILDFLAG(IS_BSD)
 #include <linux/wireless.h>
+#endif
 #include <string.h>
 #include <sys/ioctl.h>
 #include <sys/socket.h>
@@ -24,6 +28,7 @@ bool MaybeGetWifiSSID(const std::string& if_name, std:
 bool MaybeGetWifiSSID(const std::string& if_name, std::string* ssid_out) {
   DCHECK(ssid_out);
 
+#if !BUILDFLAG(IS_BSD)
   base::ScopedFD ioctl_socket(socket(AF_INET, SOCK_DGRAM, 0));
   if (!ioctl_socket.is_valid()) {
     // AF_INET is for IPv4, so it may fail for IPv6-only hosts even when there
@@ -46,6 +51,7 @@ bool MaybeGetWifiSSID(const std::string& if_name, std:
     ssid_out->assign(ssid);
     return true;
   }
+#endif
   return false;
 }
 
