--- src/cpp/desktop/DesktopMain.cpp.orig	2019-02-16 02:00:24 UTC
+++ src/cpp/desktop/DesktopMain.cpp
@@ -41,6 +41,7 @@
 #include "DesktopProgressActivator.hpp"
 #include "DesktopNetworkProxyFactory.hpp"
 #include "DesktopActivationOverlay.hpp"
+#include "global-setenv.h"
 
 #ifdef _WIN32
 #include <Windows.h>
@@ -324,7 +325,7 @@ QString inferDefaultRenderingEngine()
 
 #endif
 
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
 
 QString inferDefaultRenderingEngine()
 {
@@ -383,6 +384,7 @@ void initializeRenderingEngine(std::vect
 
 int main(int argc, char* argv[])
 {
+   GLOBAL_SETENV
    core::system::initHook();
 
    try
