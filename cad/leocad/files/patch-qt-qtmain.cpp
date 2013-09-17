--- qt/qtmain.cpp.orig	2013-08-13 06:54:12.000000000 +0200
+++ qt/qtmain.cpp	2013-08-30 23:52:45.000000000 +0200
@@ -149,6 +149,10 @@
 	const char* libPath = LC_INSTALL_PREFIX"/share/leocad/";
 #endif
 
+#ifdef Q_OS_FREEBSD
+	const char* libPath = LC_INSTALL_PREFIX"/local/share/leocad/";
+#endif
+
 #ifdef Q_OS_MAC
 	QDir bundlePath = QDir(QCoreApplication::applicationDirPath());
 	bundlePath.cdUp();
