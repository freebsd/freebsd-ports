--- chrome/updater/util/posix_util.cc.orig	2023-03-30 00:33:46 UTC
+++ chrome/updater/util/posix_util.cc
@@ -10,7 +10,7 @@
 #include "chrome/updater/updater_branding.h"
 #include "chrome/updater/util/util.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/updater/util/linux_util.h"
 #endif
 
