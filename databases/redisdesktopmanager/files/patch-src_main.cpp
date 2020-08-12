--- src/main.cpp.orig	2020-08-10 20:08:12 UTC
+++ src/main.cpp
@@ -13,9 +13,7 @@
 #include "crashpad/handler.h"
 #endif
 
-#ifdef LINUX_SIGNALS
 #include <sigwatch.h>
-#endif
 
 #include "app/app.h"
 
@@ -50,12 +48,10 @@ int main(int argc, char *argv[])
 
     Application a(argc, argv);
 
-#ifdef LINUX_SIGNALS
     UnixSignalWatcher sigwatch;
     sigwatch.watchForSignal(SIGINT);
     sigwatch.watchForSignal(SIGTERM);
     QObject::connect(&sigwatch, SIGNAL(unixSignal(int)), &a, SLOT(quit()));
-#endif
     a.initModels();
     a.initQml();
     returnCode = a.exec();
