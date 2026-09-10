--- chrome/common/extensions/permissions/chrome_permission_message_rules.cc.orig	2026-03-13 16:54:03 UTC
+++ chrome/common/extensions/permissions/chrome_permission_message_rules.cc
@@ -281,7 +281,7 @@ int GetEnterpriseReportingPrivatePermissionMessageId()
 int GetEnterpriseReportingPrivatePermissionMessageId() {
 #if BUILDFLAG(IS_WIN)
   return IDS_EXTENSION_PROMPT_WARNING_ENTERPRISE_REPORTING_PRIVATE_ENABLED_WIN;
-#elif BUILDFLAG(IS_LINUX) or BUILDFLAG(IS_MAC)
+#elif BUILDFLAG(IS_LINUX) or BUILDFLAG(IS_MAC) or BUILDFLAG(IS_BSD)
   return IDS_EXTENSION_PROMPT_WARNING_ENTERPRISE_REPORTING_PRIVATE_ENABLED_LINUX_AND_MACOS;
 #else
   return IDS_EXTENSION_PROMPT_WARNING_ENTERPRISE_REPORTING_PRIVATE;
