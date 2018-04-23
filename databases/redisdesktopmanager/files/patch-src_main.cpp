--- src/main.cpp.orig	2018-04-13 11:23:13 UTC
+++ src/main.cpp
@@ -5,9 +5,7 @@
 #include "app/app.h"
 #include "modules/crashhandler/crashhandler.h"
 
-#ifdef Q_OS_LINUX
 #include <sigwatch.h>
-#endif
 
 int main(int argc, char *argv[])
 {           
@@ -15,23 +13,14 @@ int main(int argc, char *argv[])
     QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
 #endif
 
-    #ifndef QT_DEBUG
-    QFileInfo appPath(QString::fromLocal8Bit(argv[0]));
-    QString appDir(appPath.absoluteDir().path());
-    QString crashReporterPath = QString("%1/crashreporter").arg(appDir.isEmpty() ? "." : appDir);
-    CrashHandler::instance()->Init(QDir::homePath(), appDir, crashReporterPath);
-    #endif
-
     Application a(argc, argv);
     a.initModels();
     a.initQml();
 
-    #ifdef Q_OS_LINUX
     UnixSignalWatcher sigwatch;
     sigwatch.watchForSignal(SIGINT);
     sigwatch.watchForSignal(SIGTERM);
     QObject::connect(&sigwatch, SIGNAL(unixSignal(int)), &a, SLOT(quit()));
-    #endif
 
     return a.exec();
 }
