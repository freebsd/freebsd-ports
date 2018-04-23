--- src/app/app.cpp.orig	2018-04-13 11:23:13 UTC
+++ src/app/app.cpp
@@ -210,8 +210,6 @@ void Application::initConnectionsManager()
 
 void Application::initUpdater()
 {
-    m_updater = QSharedPointer<Updater>(new Updater());
-    connect(m_updater.data(), SIGNAL(updateUrlRetrived(QString &)), this, SLOT(OnNewUpdateAvailable(QString &)));
 }
 
 void Application::installTranslator()
