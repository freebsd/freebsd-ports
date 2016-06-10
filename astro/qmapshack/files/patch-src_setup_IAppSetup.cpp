--- src/setup/IAppSetup.cpp.orig	2016-06-04 19:55:57 UTC
+++ src/setup/IAppSetup.cpp
@@ -36,7 +36,7 @@ IAppSetup* IAppSetup::getPlatformInstanc
     {
 #if defined(Q_OS_MAC)
         instance = new CAppSetupMac();
-#elif defined(Q_OS_LINUX)
+#elif defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
         instance = new CAppSetupLinux();
 #elif defined (Q_OS_WIN32)
         instance = new CAppSetupWin();
