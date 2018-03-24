--- src/gui/generalsettings.cpp.orig	2017-12-20 15:03:02 UTC
+++ src/gui/generalsettings.cpp
@@ -117,6 +117,7 @@ void GeneralSettings::loadMiscSettings()
 
 void GeneralSettings::slotUpdateInfo()
 {
+#if 0
     // Note: the sparkle-updater is not an OCUpdater
     OCUpdater *updater = qobject_cast<OCUpdater *>(Updater::instance());
     if (ConfigFile().skipUpdateCheck()) {
@@ -133,6 +134,7 @@ void GeneralSettings::slotUpdateInfo()
         // can't have those infos from sparkle currently
         _ui->updatesGroupBox->setVisible(false);
     }
+#endif
 }
 
 void GeneralSettings::saveMiscSettings()
