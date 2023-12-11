--- chrome/browser/enterprise/connectors/reporting/realtime_reporting_client.cc.orig	2023-10-19 19:58:04 UTC
+++ chrome/browser/enterprise/connectors/reporting/realtime_reporting_client.cc
@@ -55,7 +55,7 @@
 #include "base/strings/utf_string_conversions.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/signals/signals_aggregator_factory.h"
 #include "components/device_signals/core/browser/signals_aggregator.h"
 #include "components/device_signals/core/common/signals_constants.h"
@@ -140,7 +140,7 @@ void UploadSecurityEventReport(base::Value::Dict event
       std::move(upload_callback));
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void PopulateSignals(base::Value::Dict event,
                      policy::CloudPolicyClient* client,
                      std::string name,
@@ -427,7 +427,7 @@ void RealtimeReportingClient::ReportPastEvent(const st
                            /*include_profile_user_name=*/false);
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 void AddCrowdstrikeSignalsToEvent(
     base::Value::Dict& event,
@@ -486,7 +486,7 @@ void RealtimeReportingClient::ReportEventWithTimestamp
   if (include_profile_user_name) {
     event.Set(kKeyProfileUserName, GetProfileUserName());
   }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   Profile* profile = Profile::FromBrowserContext(context_);
   device_signals::SignalsAggregator* signals_aggregator =
       enterprise_signals::SignalsAggregatorFactory::GetForProfile(profile);
