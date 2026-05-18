--- components/metrics/drive_metrics_provider.cc.orig	2026-04-28 21:06:17 UTC
+++ components/metrics/drive_metrics_provider.cc
@@ -23,7 +23,7 @@ namespace {
 namespace metrics {
 
 namespace {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // These values are persisted to logs. Entries should not be renumbered and
 // numeric values should never be reused.
 enum class OptionalBoolRecord {
@@ -133,7 +133,7 @@ void DriveMetricsProvider::FillDriveMetrics(
     drive->set_has_seek_penalty(local_state_->GetBoolean(pref_name));
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   RecordTriStateMetric("UMA.DriveIsRemovableResult", response.is_removable);
 #endif
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
