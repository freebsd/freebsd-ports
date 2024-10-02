--- src/cpp/desktop/DesktopMain.cpp.orig	2021-05-24 22:22:25 UTC
+++ src/cpp/desktop/DesktopMain.cpp
@@ -49,6 +49,8 @@
 #include "DesktopActivationOverlay.hpp"
 #include "DesktopSessionServersOverlay.hpp"
 
+#include "global-setenv.h"
+
 #ifdef _WIN32
 #include <core/system/RegistryKey.hpp>
 #include <Windows.h>
@@ -349,7 +351,7 @@ QString inferDefaultRenderingEngineMac()
 
 #endif /* Q_OS_MAC */
 
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
 
 QString inferDefaultRenderingEngineLinux()
 {
@@ -477,6 +479,7 @@ std::string getSessionUrl()
 
 int main(int argc, char* argv[])
 {
+   GLOBAL_SETENV
    core::system::initHook();
 
    try
