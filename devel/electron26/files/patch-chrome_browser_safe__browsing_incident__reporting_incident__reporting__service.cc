--- chrome/browser/safe_browsing/incident_reporting/incident_reporting_service.cc.orig	2023-02-01 18:43:12 UTC
+++ chrome/browser/safe_browsing/incident_reporting/incident_reporting_service.cc
@@ -705,7 +705,7 @@ void IncidentReportingService::OnEnvironmentDataCollec
 
 // Process::Current().CreationTime() is missing on some platforms.
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   base::TimeDelta uptime =
       first_incident_time_ - base::Process::Current().CreationTime();
   environment_data->mutable_process()->set_uptime_msec(uptime.InMilliseconds());
