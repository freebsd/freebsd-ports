--- src/gui/generalsettings.cpp.orig	2016-05-12 07:59:12 UTC
+++ src/gui/generalsettings.cpp
@@ -109,6 +109,7 @@ void GeneralSettings::loadMiscSettings()
 
 void GeneralSettings::slotUpdateInfo()
 {
+#if 0
     OCUpdater *updater = dynamic_cast<OCUpdater*>(Updater::instance());
     if (ConfigFile().skipUpdateCheck()) {
         updater = 0; // don't show update info if updates are disabled
@@ -121,9 +122,12 @@ void GeneralSettings::slotUpdateInfo()
         _ui->updateStateLabel->setText(updater->statusString());
         _ui->restartButton->setVisible(updater->downloadState() == OCUpdater::DownloadComplete);
     } else {
+#endif
         // can't have those infos from sparkle currently
         _ui->updatesGroupBox->setVisible(false);
+#if 0
     }
+#endif
 }
 
 void GeneralSettings::saveMiscSettings()
