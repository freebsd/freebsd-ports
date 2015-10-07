--- src/gui/generalsettings.cpp.orig	2015-09-01 13:50:21 UTC
+++ src/gui/generalsettings.cpp
@@ -105,6 +105,7 @@ void GeneralSettings::loadMiscSettings()
 
 void GeneralSettings::slotUpdateInfo()
 {
+#if 0
     if (OCUpdater *updater = dynamic_cast<OCUpdater*>(Updater::instance())) {
         connect(updater, SIGNAL(downloadStateChanged()), SLOT(slotUpdateInfo()), Qt::UniqueConnection);
         connect(_ui->restartButton, SIGNAL(clicked()), updater, SLOT(slotStartInstaller()), Qt::UniqueConnection);
@@ -112,9 +113,12 @@ void GeneralSettings::slotUpdateInfo()
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
