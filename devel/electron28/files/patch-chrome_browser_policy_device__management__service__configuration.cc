--- chrome/browser/policy/device_management_service_configuration.cc.orig	2023-08-10 01:48:35 UTC
+++ chrome/browser/policy/device_management_service_configuration.cc
@@ -22,7 +22,7 @@
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) ||           \
     ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && \
-     !BUILDFLAG(IS_ANDROID))
+     !BUILDFLAG(IS_ANDROID)) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/connectors/common.h"
 #include "chrome/browser/enterprise/connectors/connectors_service.h"
 #endif
@@ -100,7 +100,7 @@ DeviceManagementServiceConfiguration::GetReportingConn
     content::BrowserContext* context) const {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) ||           \
     ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && \
-     !BUILDFLAG(IS_ANDROID))
+     !BUILDFLAG(IS_ANDROID)) || BUILDFLAG(IS_BSD)
   auto* service =
       enterprise_connectors::ConnectorsServiceFactory::GetForBrowserContext(
           context);
