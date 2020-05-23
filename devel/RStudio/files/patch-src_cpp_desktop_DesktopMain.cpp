--- src/cpp/desktop/DesktopMain.cpp.orig	2020-05-18 18:11:10 UTC
+++ src/cpp/desktop/DesktopMain.cpp
@@ -47,6 +47,8 @@
 #include "DesktopActivationOverlay.hpp"
 #include "DesktopSessionServersOverlay.hpp"
 
+#include "global-setenv.h"
+
 #ifdef _WIN32
 #include <core/system/RegistryKey.hpp>
 #include <Windows.h>
@@ -372,7 +374,7 @@ QString inferDefaultRenderingEngine()
 
 #endif
 
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
 
 QString inferDefaultRenderingEngine()
 {
@@ -461,6 +463,7 @@ std::string getSessionUrl()
 
 int main(int argc, char* argv[])
 {
+   GLOBAL_SETENV
    core::system::initHook();
 
    try
