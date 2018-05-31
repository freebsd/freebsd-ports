--- src/cpp/desktop/DesktopMain.cpp.orig	2018-05-16 18:21:36 UTC
+++ src/cpp/desktop/DesktopMain.cpp
@@ -40,6 +40,7 @@
 #include "DesktopProgressActivator.hpp"
 #include "DesktopNetworkProxyFactory.hpp"
 #include "DesktopActivationOverlay.hpp"
+#include "global-setenv.h"
 
 QProcess* pRSessionProcess;
 QString sharedSecret;
@@ -262,6 +263,7 @@ bool useChromiumDevtools()
 
 int main(int argc, char* argv[])
 {
+   GLOBAL_SETENV
    core::system::initHook();
 
    try
