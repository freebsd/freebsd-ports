--- chrome/browser/safe_browsing/cloud_content_scanning/binary_upload_service.cc.orig	2022-09-24 10:57:32 UTC
+++ chrome/browser/safe_browsing/cloud_content_scanning/binary_upload_service.cc
@@ -17,7 +17,7 @@
 #include "net/base/url_util.h"
 #include "third_party/abseil-cpp/absl/types/variant.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/connectors/analysis/local_binary_upload_service_factory.h"
 #endif
 
@@ -287,7 +287,7 @@ BinaryUploadService* BinaryUploadService::GetForProfil
     Profile* profile,
     const enterprise_connectors::AnalysisSettings& settings) {
   // Local content analysis is supported only on desktop platforms.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (settings.cloud_or_local_settings.is_cloud_analysis()) {
     return CloudBinaryUploadServiceFactory::GetForProfile(profile);
   } else {
