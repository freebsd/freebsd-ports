--- chrome/browser/ui/views/first_run_dialog.cc.orig	2022-05-19 05:17:39 UTC
+++ chrome/browser/ui/views/first_run_dialog.cc
@@ -38,7 +38,7 @@
 
 namespace {
 
-#if !BUILDFLAG(IS_MAC)
+#if !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_BSD)
 void InitCrashReporterIfEnabled(bool enabled) {
   if (!crash_reporter::IsCrashpadEnabled() && enabled)
     breakpad::InitCrashReporter(std::string());
@@ -122,7 +122,7 @@ bool FirstRunDialog::Accept() {
 
 #if BUILDFLAG(IS_MAC)
   ChangeMetricsReportingState(report_crashes_->GetChecked());
-#else
+#elif !BUILDFLAG(IS_BSD)
 #if BUILDFLAG(IS_CHROMEOS_ASH)
   metrics::structured::NeutrinoDevicesLog(
       metrics::structured::NeutrinoDevicesLocation::kFirstRunDialog);
