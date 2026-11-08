--- src/gui/config_dialog/config_dialog.cc.orig	2026-10-18 07:08:38 UTC
+++ src/gui/config_dialog/config_dialog.cc
@@ -121,21 +121,21 @@ ConfigDialog::ConfigDialog()
   setWindowTitle(tr("%1 Preferences").arg(GuiUtil::ProductName()));
 #endif  // __APPLE__
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
   miscDefaultIMEWidget->setVisible(false);
   miscAdministrationWidget->setVisible(false);
   miscStartupWidget->setVisible(false);
-#endif  // __linux__
+#endif  // __linux__ || __FreeBSD__
 
 #ifdef NDEBUG
   // disable logging options
   miscLoggingWidget->setVisible(false);
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
   // The last "misc" tab has no valid configs on Linux
   constexpr int kMiscTabIndex = 6;
   configDialogTabWidget->removeTab(kMiscTabIndex);
-#endif  // __linux__
+#endif  // __linux__ || __FreeBSD__
 #endif  // NDEBUG
 
   suggestionsSizeSpinBox->setRange(1, 9);
@@ -293,7 +293,7 @@ ConfigDialog::ConfigDialog()
   dictionaryPreloadingAndUACLabel->setVisible(false);
 #endif  // _WIN32
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
   // On Linux, disable all fields for UsageStats
   usageStatsLabel->setEnabled(false);
   usageStatsLabel->setVisible(false);
@@ -303,7 +303,7 @@ ConfigDialog::ConfigDialog()
   usageStatsMessage->setVisible(false);
   usageStatsCheckBox->setEnabled(false);
   usageStatsCheckBox->setVisible(false);
-#endif  // __linux__
+#endif  // __linux__ || __FreeBSD__
 
   GuiUtil::ReplaceWidgetLabels(this);
 
