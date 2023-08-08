--- chrome/browser/ui/webui/management/management_ui_handler.cc.orig	2023-05-25 00:41:46 UTC
+++ chrome/browser/ui/webui/management/management_ui_handler.cc
@@ -172,7 +172,7 @@ enum class ReportingType {
   kUserActivity
 };
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const char kManagementScreenCaptureEvent[] = "managementScreenCaptureEvent";
 const char kManagementScreenCaptureData[] = "managementScreenCaptureData";
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
@@ -974,7 +974,7 @@ base::Value::Dict ManagementUIHandler::GetThreatProtec
                                   kManagementOnPageVisitedVisibleData, &info);
   }
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (capture_policy::IsGetDisplayMediaSetSelectAllScreensAllowedForAnySite(
           profile)) {
     AddThreatProtectionPermission(kManagementScreenCaptureEvent,
