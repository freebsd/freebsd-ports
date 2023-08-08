--- chrome/updater/updater.cc.orig	2023-02-01 18:43:15 UTC
+++ chrome/updater/updater.cc
@@ -49,7 +49,7 @@
 #include "chrome/updater/util/win_util.h"
 #elif BUILDFLAG(IS_MAC)
 #include "chrome/updater/app/server/mac/server.h"
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/updater/app/server/linux/server.h"
 #endif
 
