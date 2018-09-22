--- src/app/app.cpp.orig	2018-08-31 12:53:12 UTC
+++ src/app/app.cpp
@@ -224,8 +224,6 @@ void Application::initConnectionsManager()
 
 void Application::initUpdater()
 {
-    m_updater = QSharedPointer<Updater>(new Updater());
-    connect(m_updater.data(), SIGNAL(updateUrlRetrived(QString &)), this, SLOT(OnNewUpdateAvailable(QString &)));
 }
 
 void Application::installTranslator()
