--- services/device/hid/hid_service.cc.orig	2022-11-30 08:12:58 UTC
+++ services/device/hid/hid_service.cc
@@ -20,6 +20,10 @@
 
 #if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && defined(USE_UDEV)
 #include "services/device/hid/hid_service_linux.h"
+#elif BUILDFLAG(IS_OPENBSD)
+#include "services/device/hid/hid_service_fido.h"
+#elif BUILDFLAG(IS_FREEBSD)
+#include "services/device/hid/hid_service_freebsd.h"
 #elif BUILDFLAG(IS_MAC)
 #include "services/device/hid/hid_service_mac.h"
 #elif BUILDFLAG(IS_WIN)
@@ -68,6 +72,10 @@ constexpr base::TaskTraits HidService::kBlockingTaskTr
 std::unique_ptr<HidService> HidService::Create() {
 #if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && defined(USE_UDEV)
   return std::make_unique<HidServiceLinux>();
+#elif BUILDFLAG(IS_OPENBSD)
+  return std::make_unique<HidServiceFido>();
+#elif BUILDFLAG(IS_FREEBSD)
+  return std::make_unique<HidServiceFreeBSD>();
 #elif BUILDFLAG(IS_MAC)
   return std::make_unique<HidServiceMac>();
 #elif BUILDFLAG(IS_WIN)
