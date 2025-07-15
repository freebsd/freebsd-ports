--- components/device_signals/core/common/linux/platform_utils_linux.cc.orig	2025-06-30 07:04:30 UTC
+++ components/device_signals/core/common/linux/platform_utils_linux.cc
@@ -4,12 +4,23 @@
 
 #include "components/device_signals/core/common/platform_utils.h"
 
+#include "build/build_config.h"
+
 #if defined(USE_GIO)
 #include <gio/gio.h>
 #endif  // defined(USE_GIO)
 #include <sys/stat.h>
+#if !BUILDFLAG(IS_BSD)
 #include <sys/sysmacros.h>
+#endif
 
+#if BUILDFLAG(IS_BSD)
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <ifaddrs.h>
+#include <net/if_dl.h>
+#endif
+
 #include <algorithm>
 #include <optional>
 #include <string>
@@ -98,6 +109,7 @@ SettingValue GetDiskEncrypted() {
 // Implements the logic from the native host installation script. First find the
 // root device identifier, then locate its parent and get its type.
 SettingValue GetDiskEncrypted() {
+#if !BUILDFLAG(IS_BSD)
   struct stat info;
   // First figure out the device identifier. Fail fast if this fails.
   if (stat("/", &info) != 0) {
@@ -120,11 +132,35 @@ SettingValue GetDiskEncrypted() {
     }
     return SettingValue::UNKNOWN;
   }
+#endif
   return SettingValue::DISABLED;
 }
 
 std::vector<std::string> GetMacAddresses() {
   std::vector<std::string> result;
+#if BUILDFLAG(IS_BSD)
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
   if (!reader.IsValid()) {
     return result;
@@ -149,6 +185,7 @@ std::vector<std::string> GetMacAddresses() {
                               &address);
     result.push_back(address);
   }
+#endif
   return result;
 }
 
