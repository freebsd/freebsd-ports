--- chrome/browser/safe_browsing/cloud_content_scanning/binary_upload_service.cc.orig	2025-04-22 20:15:27 UTC
+++ chrome/browser/safe_browsing/cloud_content_scanning/binary_upload_service.cc
@@ -20,7 +20,7 @@
 #include "components/safe_browsing/core/common/safebrowsing_switches.h"
 #include "net/base/url_util.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/connectors/analysis/local_binary_upload_service_factory.h"
 #endif
 
