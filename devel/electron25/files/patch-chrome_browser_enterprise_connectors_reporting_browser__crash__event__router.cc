--- chrome/browser/enterprise/connectors/reporting/browser_crash_event_router.cc.orig	2023-03-30 00:33:42 UTC
+++ chrome/browser/enterprise/connectors/reporting/browser_crash_event_router.cc
@@ -14,7 +14,7 @@ BrowserCrashEventRouter::BrowserCrashEventRouter(
   if (!base::FeatureList::IsEnabled(kBrowserCrashEventsEnabled)) {
     return;
   }
-#if !BUILDFLAG(IS_FUCHSIA) && !BUILDFLAG(IS_CHROMEOS_ASH)
+#if !BUILDFLAG(IS_FUCHSIA) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_BSD)
   CrashReportingContext* crash_reporting_context =
       CrashReportingContext::GetInstance();
   Profile* profile = Profile::FromBrowserContext(context);
@@ -27,7 +27,7 @@ BrowserCrashEventRouter::~BrowserCrashEventRouter() {
   if (!base::FeatureList::IsEnabled(kBrowserCrashEventsEnabled)) {
     return;
   }
-#if !BUILDFLAG(IS_FUCHSIA) && !BUILDFLAG(IS_CHROMEOS_ASH)
+#if !BUILDFLAG(IS_FUCHSIA) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_BSD)
   CrashReportingContext* crash_reporting_context =
       CrashReportingContext::GetInstance();
   crash_reporting_context->RemoveProfile(this);
