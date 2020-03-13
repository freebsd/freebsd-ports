--- chrome/browser/media/router/discovery/discovery_network_list_wifi_linux.cc.orig	2019-12-12 12:39:11 UTC
+++ chrome/browser/media/router/discovery/discovery_network_list_wifi_linux.cc
@@ -9,8 +9,6 @@
 #include <sys/socket.h>
 #include <sys/types.h>
 
-#include <linux/wireless.h>
-
 #include "base/files/scoped_file.h"
 #include "base/logging.h"
 #include "net/base/network_interfaces_linux.h"
@@ -20,6 +18,7 @@ namespace media_router {
 bool MaybeGetWifiSSID(const std::string& if_name, std::string* ssid_out) {
   DCHECK(ssid_out);
 
+#if !defined(OS_BSD)
   base::ScopedFD ioctl_socket(socket(AF_INET, SOCK_DGRAM, 0));
   if (!ioctl_socket.is_valid()) {
     // AF_INET is for IPv4, so it may fail for IPv6-only hosts even when there
@@ -41,6 +40,7 @@ bool MaybeGetWifiSSID(const std::string& if_name, std:
     ssid_out->assign(ssid);
     return true;
   }
+#endif
   return false;
 }
 
