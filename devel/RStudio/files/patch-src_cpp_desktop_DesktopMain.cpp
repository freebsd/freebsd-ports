--- src/cpp/desktop/DesktopMain.cpp.orig	2017-11-16 21:40:37 UTC
+++ src/cpp/desktop/DesktopMain.cpp
@@ -42,6 +42,7 @@
 #include "DesktopSessionLauncher.hpp"
 #include "DesktopProgressActivator.hpp"
 #include "DesktopNetworkProxyFactory.hpp"
+#include "global-setenv.h"
 
 QProcess* pRSessionProcess;
 QString sharedSecret;
@@ -198,6 +199,7 @@ bool isNonProjectFilename(QString filena
 
 int main(int argc, char* argv[])
 {
+   GLOBAL_SETENV
    core::system::initHook();
 
    try
