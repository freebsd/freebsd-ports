--- chrome/browser/ui/views/first_run_dialog.cc.orig	2021-01-07 00:36:25 UTC
+++ chrome/browser/ui/views/first_run_dialog.cc
@@ -114,9 +114,11 @@ void FirstRunDialog::Done() {
 bool FirstRunDialog::Accept() {
   GetWidget()->Hide();
 
+#if !defined(OS_BSD)
   ChangeMetricsReportingStateWithReply(
       report_crashes_->GetChecked(),
       base::BindRepeating(&InitCrashReporterIfEnabled));
+#endif
 
   if (make_default_->GetChecked())
     shell_integration::SetAsDefaultBrowser();
