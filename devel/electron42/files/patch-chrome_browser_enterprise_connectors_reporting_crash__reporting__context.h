--- chrome/browser/enterprise/connectors/reporting/crash_reporting_context.h.orig	2026-04-28 21:06:17 UTC
+++ chrome/browser/enterprise/connectors/reporting/crash_reporting_context.h
@@ -11,7 +11,7 @@
 #include "chrome/browser/enterprise/connectors/reporting/browser_crash_event_router.h"
 #include "components/enterprise/browser/controller/chrome_browser_cloud_management_controller.h"
 
-#if !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
 #include "third_party/crashpad/crashpad/client/crash_report_database.h"
 #endif
 
@@ -30,7 +30,7 @@ class CrashReportingContext
   CrashReportingContext operator=(CrashReportingContext&&) = delete;
   ~CrashReportingContext() override;
 
-#if !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
   static CrashReportingContext* GetInstance();
 
   void AddProfile(BrowserCrashEventRouter* router, Profile* profile);
@@ -54,7 +54,7 @@ class CrashReportingContext
 #endif
 };
 
-#if !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
 
 // Utility function to parse reports from a crash database that were
 // created past a given timestamp. Included in header for testing.
