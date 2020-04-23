--- src/cpp/desktop/DesktopMain.cpp.orig	2020-04-01 16:16:24 UTC
+++ src/cpp/desktop/DesktopMain.cpp
@@ -42,6 +42,8 @@
 #include "DesktopNetworkProxyFactory.hpp"
 #include "DesktopActivationOverlay.hpp"
 
+#include "global-setenv.h"
+
 #ifdef _WIN32
 #include <core/system/RegistryKey.hpp>
 #include <Windows.h>
@@ -367,7 +369,7 @@ QString inferDefaultRenderingEngine()
 
 #endif
 
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
 
 QString inferDefaultRenderingEngine()
 {
@@ -426,6 +428,7 @@ void initializeRenderingEngine(std::vector<char*>* pAr
 
 int main(int argc, char* argv[])
 {
+   GLOBAL_SETENV
    core::system::initHook();
 
    try
