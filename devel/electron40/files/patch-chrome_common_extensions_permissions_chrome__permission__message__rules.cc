--- chrome/common/extensions/permissions/chrome_permission_message_rules.cc.orig	2025-03-24 20:50:14 UTC
+++ chrome/common/extensions/permissions/chrome_permission_message_rules.cc
@@ -280,7 +280,7 @@ int GetEnterpriseReportingPrivatePermissionMessageId()
 int GetEnterpriseReportingPrivatePermissionMessageId() {
 #if BUILDFLAG(IS_WIN)
   return IDS_EXTENSION_PROMPT_WARNING_ENTERPRISE_REPORTING_PRIVATE_ENABLED_WIN;
-#elif BUILDFLAG(IS_LINUX) or BUILDFLAG(IS_MAC)
+#elif BUILDFLAG(IS_LINUX) or BUILDFLAG(IS_MAC) or BUILDFLAG(IS_BSD)
   return IDS_EXTENSION_PROMPT_WARNING_ENTERPRISE_REPORTING_PRIVATE_ENABLED_LINUX_AND_MACOS;
 #else
   return IDS_EXTENSION_PROMPT_WARNING_ENTERPRISE_REPORTING_PRIVATE;
