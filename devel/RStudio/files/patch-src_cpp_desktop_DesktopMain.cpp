--- src/cpp/desktop/DesktopMain.cpp.orig	2020-01-23 23:30:24 UTC
+++ src/cpp/desktop/DesktopMain.cpp
@@ -46,6 +46,7 @@
 #include "DesktopNetworkProxyFactory.hpp"
 #include "DesktopActivationOverlay.hpp"
 #include "DesktopSessionServersOverlay.hpp"
+#include "global-setenv.h"
 
 #ifdef _WIN32
 #include <core/system/RegistryKey.hpp>
@@ -372,7 +373,7 @@ QString inferDefaultRenderingEngine()
 
 #endif
 
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
 
 QString inferDefaultRenderingEngine()
 {
@@ -461,6 +462,7 @@ std::string getSessionUrl()
 
 int main(int argc, char* argv[])
 {
+   GLOBAL_SETENV
    core::system::initHook();
 
    try
