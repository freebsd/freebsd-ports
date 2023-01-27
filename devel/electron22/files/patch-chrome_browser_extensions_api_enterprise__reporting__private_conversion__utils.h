--- chrome/browser/extensions/api/enterprise_reporting_private/conversion_utils.h.orig	2022-08-31 12:19:35 UTC
+++ chrome/browser/extensions/api/enterprise_reporting_private/conversion_utils.h
@@ -7,7 +7,7 @@
 
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 #include <vector>
 
