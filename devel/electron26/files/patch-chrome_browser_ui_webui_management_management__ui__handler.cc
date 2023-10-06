--- chrome/browser/ui/webui/management/management_ui_handler.cc.orig	2023-08-10 01:48:37 UTC
+++ chrome/browser/ui/webui/management/management_ui_handler.cc
@@ -86,7 +86,7 @@
 #include "components/policy/core/common/cloud/user_cloud_policy_manager.h"
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/signals/user_permission_service_factory.h"
 #include "components/device_signals/core/browser/user_permission_service.h"  // nogncheck
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
@@ -178,12 +178,12 @@ enum class ReportingType {
   kUserActivity
 };
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const char kManagementScreenCaptureEvent[] = "managementScreenCaptureEvent";
 const char kManagementScreenCaptureData[] = "managementScreenCaptureData";
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const char kManagementDeviceSignalsDisclosure[] =
     "managementDeviceSignalsDisclosure";
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
@@ -738,7 +738,7 @@ void ManagementUIHandler::AddReportingInfo(base::Value
              GetReportingTypeValue(report_definition.reporting_type));
     report_sources->Append(std::move(data));
   }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Insert the device signals consent disclosure at the end of browser
   // reporting section.
   auto* user_permission_service = GetUserPermissionService();
@@ -1015,7 +1015,7 @@ base::Value::Dict ManagementUIHandler::GetThreatProtec
                                   kManagementOnPageVisitedVisibleData, &info);
   }
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (capture_policy::IsGetAllScreensMediaAllowedForAnySite(profile)) {
     AddThreatProtectionPermission(kManagementScreenCaptureEvent,
                                   kManagementScreenCaptureData, &info);
@@ -1060,7 +1060,7 @@ policy::PolicyService* ManagementUIHandler::GetPolicyS
       ->policy_service();
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 device_signals::UserPermissionService*
 ManagementUIHandler::GetUserPermissionService() {
   return enterprise_signals::UserPermissionServiceFactory::GetForProfile(
