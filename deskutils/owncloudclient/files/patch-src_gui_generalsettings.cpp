--- src/gui/generalsettings.cpp.orig	2016-05-12 07:59:12 UTC
+++ src/gui/generalsettings.cpp
@@ -124,6 +124,7 @@
 
 void GeneralSettings::slotUpdateInfo()
 {
+#if 0
     // Note: the sparkle-updater is not an OCUpdater
     OCUpdater *updater = qobject_cast<OCUpdater*>(Updater::instance());
     if (ConfigFile().skipUpdateCheck()) {
@@ -140,6 +141,7 @@
         // can't have those infos from sparkle currently
         _ui->updatesGroupBox->setVisible(false);
     }
+#endif
 }
 
 void GeneralSettings::saveMiscSettings()
