--- chrome/browser/glic/service/glic_instance_impl.cc.orig	2026-08-24 20:59:34 UTC
+++ chrome/browser/glic/service/glic_instance_impl.cc
@@ -80,7 +80,7 @@
 #include "ui/base/l10n/l10n_util.h"
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/reporting/saas_usage/saas_usage_reporting_controller_factory.h"
 #endif
 
@@ -158,7 +158,7 @@ GetSaasUsageReportingController(Profile* profile) {
 enterprise_reporting::SaasUsageReportingController*
 GetSaasUsageReportingController(Profile* profile) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return enterprise_reporting::SaasUsageReportingControllerFactory::
       GetForProfile(profile);
 #else
