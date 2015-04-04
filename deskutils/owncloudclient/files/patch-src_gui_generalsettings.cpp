--- src/gui/generalsettings.cpp.orig	2015-03-16 14:28:58 UTC
+++ src/gui/generalsettings.cpp
@@ -85,6 +85,7 @@ void GeneralSettings::loadMiscSettings()
 
 void GeneralSettings::slotUpdateInfo()
 {
+#if 0
     if (OCUpdater *updater = dynamic_cast<OCUpdater*>(Updater::instance()))
     {
         connect(updater, SIGNAL(downloadStateChanged()), SLOT(slotUpdateInfo()), Qt::UniqueConnection);
@@ -93,9 +94,12 @@ void GeneralSettings::slotUpdateInfo()
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
