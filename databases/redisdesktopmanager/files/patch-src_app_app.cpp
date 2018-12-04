--- src/app/app.cpp.orig	2018-11-27 08:26:54 UTC
+++ src/app/app.cpp
@@ -37,7 +37,6 @@ Application::Application(int& argc, char** argv)
   processCmdArgs();
   initAppFonts();
   initRedisClient();
-  initUpdater();
   installTranslator();
 }
 
@@ -203,9 +202,6 @@ void Application::initQml() {
 }
 
 void Application::initUpdater() {
-  m_updater = QSharedPointer<Updater>(new Updater());
-  connect(m_updater.data(), SIGNAL(updateUrlRetrived(QString&)), this,
-          SLOT(OnNewUpdateAvailable(QString&)));
 }
 
 void Application::installTranslator() {
