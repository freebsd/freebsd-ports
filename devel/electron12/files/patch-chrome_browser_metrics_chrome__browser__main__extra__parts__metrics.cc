--- chrome/browser/metrics/chrome_browser_main_extra_parts_metrics.cc.orig	2021-04-14 01:08:40 UTC
+++ chrome/browser/metrics/chrome_browser_main_extra_parts_metrics.cc
@@ -56,7 +56,9 @@
 // of lacros-chrome is complete.
 #if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
 #include <gnu/libc-version.h>
+#endif
 
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 #include "base/linux_util.h"
 #include "base/strings/string_split.h"
 #include "base/strings/string_util.h"
@@ -65,7 +67,7 @@
 #include "ui/base/ui_base_features.h"
 #include "ui/base/x/x11_util.h"
 #endif
-#endif  // defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#endif  // defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 
 #if defined(USE_OZONE) || defined(USE_X11)
 #include "ui/events/devices/device_data_manager.h"
