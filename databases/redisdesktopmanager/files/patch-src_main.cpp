--- src/main.cpp.orig	2018-09-22 00:04:41 UTC
+++ src/main.cpp
@@ -5,9 +5,7 @@
 #include "app/app.h"
 #include "modules/crashhandler/crashhandler.h"
 
-#ifdef LINUX_SIGNALS
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
-    CrashHandler::instance()->Init(QDir::homePath(), appPath.absoluteFilePath(), crashReporterPath);
-    #endif
-
     Application a(argc, argv);
     a.initModels();
     a.initQml();
 
-    #ifdef LINUX_SIGNALS
     UnixSignalWatcher sigwatch;
     sigwatch.watchForSignal(SIGINT);
     sigwatch.watchForSignal(SIGTERM);
     QObject::connect(&sigwatch, SIGNAL(unixSignal(int)), &a, SLOT(quit()));
-    #endif
 
     return a.exec();
 }
