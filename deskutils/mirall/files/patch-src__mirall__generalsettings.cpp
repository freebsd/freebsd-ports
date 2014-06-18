--- src/mirall/generalsettings.cpp.orig
+++ src/mirall/generalsettings.cpp
@@ -76,6 +76,7 @@
 
 void GeneralSettings::slotUpdateInfo()
 {
+#if 0
     if (OCUpdater *updater = dynamic_cast<OCUpdater*>(Updater::instance()))
     {
         connect(updater, SIGNAL(downloadStateChanged()), SLOT(slotUpdateInfo()), Qt::UniqueConnection);
@@ -84,9 +85,12 @@
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
