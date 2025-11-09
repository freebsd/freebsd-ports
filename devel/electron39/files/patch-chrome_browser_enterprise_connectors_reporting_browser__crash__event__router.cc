--- chrome/browser/enterprise/connectors/reporting/browser_crash_event_router.cc.orig	2024-08-14 20:54:35 UTC
+++ chrome/browser/enterprise/connectors/reporting/browser_crash_event_router.cc
@@ -13,7 +13,7 @@ BrowserCrashEventRouter::BrowserCrashEventRouter(
 
 BrowserCrashEventRouter::BrowserCrashEventRouter(
     content::BrowserContext* context) {
-#if !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
   CrashReportingContext* crash_reporting_context =
       CrashReportingContext::GetInstance();
   Profile* profile = Profile::FromBrowserContext(context);
@@ -23,7 +23,7 @@ BrowserCrashEventRouter::~BrowserCrashEventRouter() {
 }
 
 BrowserCrashEventRouter::~BrowserCrashEventRouter() {
-#if !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
   CrashReportingContext* crash_reporting_context =
       CrashReportingContext::GetInstance();
   crash_reporting_context->RemoveProfile(this);
