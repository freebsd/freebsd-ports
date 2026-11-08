--- chrome/updater/util/posix_util.cc.orig	2026-04-28 21:06:17 UTC
+++ chrome/updater/util/posix_util.cc
@@ -22,7 +22,7 @@
 #include "chrome/updater/updater_branding.h"
 #include "chrome/updater/util/util.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/updater/util/linux_util.h"
 #endif
 
