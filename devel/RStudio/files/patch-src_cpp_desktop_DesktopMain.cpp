--- src/cpp/desktop/DesktopMain.cpp.orig	2019-09-19 13:59:21 UTC
+++ src/cpp/desktop/DesktopMain.cpp
@@ -41,6 +41,7 @@
 #include "DesktopProgressActivator.hpp"
 #include "DesktopNetworkProxyFactory.hpp"
 #include "DesktopActivationOverlay.hpp"
+#include "global-setenv.h"
 
 #ifdef _WIN32
 #include <core/system/RegistryKey.hpp>
@@ -367,7 +368,7 @@ QString inferDefaultRenderingEngine()
 
 #endif
 
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
 
 QString inferDefaultRenderingEngine()
 {
@@ -426,6 +427,7 @@ void initializeRenderingEngine(std::vector<char*>* pAr
 
 int main(int argc, char* argv[])
 {
+   GLOBAL_SETENV
    core::system::initHook();
 
    try
