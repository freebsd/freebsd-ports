--- chrome/common/extensions/permissions/chrome_permission_message_rules.cc.orig	2022-11-30 08:12:58 UTC
+++ chrome/common/extensions/permissions/chrome_permission_message_rules.cc
@@ -285,7 +285,7 @@ int GetEnterpriseReportingPrivatePermissionMessageId()
   }
 #if BUILDFLAG(IS_WIN)
   return IDS_EXTENSION_PROMPT_WARNING_ENTERPRISE_REPORTING_PRIVATE_ENABLED_WIN;
-#elif BUILDFLAG(IS_LINUX) or BUILDFLAG(IS_MAC)
+#elif BUILDFLAG(IS_LINUX) or BUILDFLAG(IS_MAC) or BUILDFLAG(IS_BSD)
   return IDS_EXTENSION_PROMPT_WARNING_ENTERPRISE_REPORTING_PRIVATE_ENABLED_LINUX_AND_MACOS;
 #else
   return IDS_EXTENSION_PROMPT_WARNING_ENTERPRISE_REPORTING_PRIVATE;
