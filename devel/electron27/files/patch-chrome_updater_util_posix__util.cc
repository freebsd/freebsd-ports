--- chrome/updater/util/posix_util.cc.orig	2023-05-25 00:41:49 UTC
+++ chrome/updater/util/posix_util.cc
@@ -16,7 +16,7 @@
 #include "chrome/updater/updater_branding.h"
 #include "chrome/updater/util/util.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/updater/util/linux_util.h"
 #endif
 
