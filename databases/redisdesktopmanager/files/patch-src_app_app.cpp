--- src/app/app.cpp.orig	2020-08-10 20:06:43 UTC
+++ src/app/app.cpp
@@ -43,9 +43,6 @@ Application::Application(int& argc, char** argv)
   processCmdArgs();
   initAppFonts();
   initRedisClient();
-#ifndef RDM_APPSTORE
-  initUpdater();
-#endif
   installTranslator();
   initPython();
 }
@@ -254,9 +251,6 @@ void Application::initQml() {
 }
 
 void Application::initUpdater() {
-  m_updater = QSharedPointer<Updater>(new Updater());
-  connect(m_updater.data(), SIGNAL(updateUrlRetrived(QString&)), this,
-          SLOT(OnNewUpdateAvailable(QString&)));
 }
 
 void Application::initPython() {
