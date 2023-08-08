--- chrome/browser/enterprise/connectors/reporting/browser_crash_event_router.h.orig	2022-10-24 13:33:33 UTC
+++ chrome/browser/enterprise/connectors/reporting/browser_crash_event_router.h
@@ -9,7 +9,7 @@
 #include "chrome/browser/enterprise/connectors/reporting/realtime_reporting_client.h"
 #include "components/enterprise/browser/controller/chrome_browser_cloud_management_controller.h"
 
-#if !BUILDFLAG(IS_FUCHSIA)
+#if !BUILDFLAG(IS_FUCHSIA) && !BUILDFLAG(IS_BSD)
 #include "third_party/crashpad/crashpad/client/crash_report_database.h"
 #endif  // !BUILDFLAG(IS_FUCHSIA)
 namespace enterprise_connectors {
@@ -27,7 +27,7 @@ class BrowserCrashEventRouter
   BrowserCrashEventRouter& operator=(const BrowserCrashEventRouter&) = delete;
   ~BrowserCrashEventRouter() override;
 
-#if !BUILDFLAG(IS_FUCHSIA)
+#if !BUILDFLAG(IS_FUCHSIA) && !BUILDFLAG(IS_BSD)
   void OnCloudReportingLaunched(
       enterprise_reporting::ReportScheduler* report_scheduler) override;
   void UploadToReportingServer(
@@ -41,7 +41,7 @@ class BrowserCrashEventRouter
       nullptr;
   raw_ptr<policy::ChromeBrowserCloudManagementController> controller_ = nullptr;
 
-#if !BUILDFLAG(IS_FUCHSIA)
+#if !BUILDFLAG(IS_FUCHSIA) && !BUILDFLAG(IS_BSD)
   // ReportCrashes() checks the enterprise policy settings, retrieves crash
   // reports from the crashpad local database and sends reports that have not
   // been sent to the reporting server.
