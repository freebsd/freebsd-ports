--- src/mixxx.cpp.orig	Tue Oct 12 22:08:14 2004
+++ src/mixxx.cpp	Tue Oct 12 22:08:35 2004
@@ -111,7 +111,7 @@
     // On Windows and Mac it is always (and only) app dir.
     //
     QString qConfigPath;
-#ifdef __LINUX__
+#if defined(__LINUX__) || defined(__FreeBSD__)
     // On Linux, check if the path is stored in the configuration database.
     if (config->getValueString(ConfigKey("[Config]","Path")).length()>0 && QDir(config->getValueString(ConfigKey("[Config]","Path"))).exists())
         qConfigPath = config->getValueString(ConfigKey("[Config]","Path"));
