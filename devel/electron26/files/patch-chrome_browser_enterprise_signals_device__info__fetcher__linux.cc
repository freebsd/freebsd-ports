--- chrome/browser/enterprise/signals/device_info_fetcher_linux.cc.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/enterprise/signals/device_info_fetcher_linux.cc
@@ -4,12 +4,23 @@
 
 #include "chrome/browser/enterprise/signals/device_info_fetcher_linux.h"
 
+#include "build/build_config.h"
+
 #if defined(USE_GIO)
 #include <gio/gio.h>
 #endif  // defined(USE_GIO)
 #include <sys/stat.h>
+#if !defined(OS_BSD)
 #include <sys/sysmacros.h>
+#endif
 
+#if defined(OS_BSD)
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <ifaddrs.h>
+#include <net/if_dl.h>
+#endif
+
 #include <string>
 
 #include "base/environment.h"
@@ -118,6 +129,7 @@ SettingValue GetScreenlockSecured() {
 // Implements the logic from the native host installation script. First find the
 // root device identifier, then locate its parent and get its type.
 SettingValue GetDiskEncrypted() {
+#if !defined(OS_BSD)
   struct stat info;
   // First figure out the device identifier. Fail fast if this fails.
   if (stat("/", &info) != 0)
@@ -139,11 +151,35 @@ SettingValue GetDiskEncrypted() {
     }
     return SettingValue::UNKNOWN;
   }
+#endif
   return SettingValue::DISABLED;
 }
 
 std::vector<std::string> GetMacAddresses() {
   std::vector<std::string> result;
+#if defined(OS_BSD)
+  struct ifaddrs* ifa = nullptr;
+
+  if (getifaddrs(&ifa) != 0)
+    return result;
+
+  struct ifaddrs* interface = ifa;
+  for (; interface != nullptr; interface = interface->ifa_next) {
+    if (interface->ifa_addr == nullptr ||
+        interface->ifa_addr->sa_family != AF_LINK) {
+      continue;
+    }
+    struct sockaddr_dl* sdl =
+        reinterpret_cast<struct sockaddr_dl*>(interface->ifa_addr);
+    if (!sdl || sdl->sdl_alen != 6)
+      continue;
+    char* link_address = static_cast<char*>(LLADDR(sdl));
+    result.push_back(base::StringPrintf(
+        "%02x:%02x:%02x:%02x:%02x:%02x", link_address[0] & 0xff,
+        link_address[1] & 0xff, link_address[2] & 0xff, link_address[3] & 0xff,
+        link_address[4] & 0xff, link_address[5] & 0xff));
+  }
+#else
   base::DirReaderPosix reader("/sys/class/net");
   if (!reader.IsValid())
     return result;
@@ -166,6 +202,7 @@ std::vector<std::string> GetMacAddresses() {
                               &address);
     result.push_back(address);
   }
+#endif
   return result;
 }
 
