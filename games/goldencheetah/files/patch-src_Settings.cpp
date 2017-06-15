--- src/Settings.cpp.orig	2015-08-12 08:43:33 UTC
+++ src/Settings.cpp
@@ -11,6 +11,8 @@ int OperatingSystem = WINDOWS;
 int OperatingSystem = LINUX;
 #elif defined Q_OS_OPENBSD
 int OperatingSystem = OPENBSD;
+#elif defined Q_OS_FREEBSD
+int OperatingSystem = FREEBSD;
 #endif
 
 static GSettings *GetApplicationSettings()
