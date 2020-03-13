--- third_party/crashpad/crashpad/util/misc/address_types.h.orig	2019-12-12 12:41:25 UTC
+++ third_party/crashpad/crashpad/util/misc/address_types.h
@@ -25,7 +25,7 @@
 #include <mach/mach_types.h>
 #elif defined(OS_WIN)
 #include "util/win/address_types.h"
-#elif defined(OS_LINUX) || defined(OS_ANDROID)
+#elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 #include "util/linux/address_types.h"
 #elif defined(OS_FUCHSIA)
 #include <zircon/types.h>
@@ -55,7 +55,7 @@ using VMSize = mach_vm_size_t;
 using VMAddress = WinVMAddress;
 using VMSize = WinVMSize;
 
-#elif defined(OS_LINUX) || defined(OS_ANDROID)
+#elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 
 using VMAddress = LinuxVMAddress;
 using VMSize = LinuxVMSize;
