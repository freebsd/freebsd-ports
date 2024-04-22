- for now treat FreeBSD as Linux for simplicity

--- carla/source/modules/AppConfig.h.orig	2023-10-24 08:52:54 UTC
+++ carla/source/modules/AppConfig.h
@@ -33,7 +33,7 @@
 # define APPCONFIG_OS_WIN32
 #elif defined(__APPLE__)
 # define APPCONFIG_OS_MAC
-#elif defined(__linux__) || defined(__linux)
+#elif defined(__linux__) || defined(__linux) || defined(__FreeBSD__)
 # define APPCONFIG_OS_LINUX
 #elif defined(__FreeBSD__)
 # define APPCONFIG_OS_FREEBSD
