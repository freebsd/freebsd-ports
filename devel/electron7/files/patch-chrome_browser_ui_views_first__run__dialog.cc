--- chrome/browser/ui/views/first_run_dialog.cc.orig	2019-12-12 12:39:17 UTC
+++ chrome/browser/ui/views/first_run_dialog.cc
@@ -37,8 +37,10 @@
 namespace {
 
 void InitCrashReporterIfEnabled(bool enabled) {
+#if !defined(OS_BSD)
   if (enabled)
     breakpad::InitCrashReporter(std::string());
+#endif
 }
 
 }  // namespace
@@ -108,8 +110,10 @@ std::unique_ptr<views::View> FirstRunDialog::CreateExt
 bool FirstRunDialog::Accept() {
   GetWidget()->Hide();
 
+#if !defined(OS_BSD)
   ChangeMetricsReportingStateWithReply(report_crashes_->GetChecked(),
                                        base::Bind(&InitCrashReporterIfEnabled));
+#endif
 
   if (make_default_->GetChecked())
     shell_integration::SetAsDefaultBrowser();
