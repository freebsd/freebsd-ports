--- ./src/mirall/application.cpp.orig	2014-03-25 17:13:11.000000000 +0100
+++ ./src/mirall/application.cpp	2014-03-25 17:13:36.000000000 +0100
@@ -64,7 +64,7 @@
 
 QString applicationTrPath()
 {
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
     return QString::fromLatin1(DATADIR"/"APPLICATION_EXECUTABLE"/i18n/");
 #endif
 #ifdef Q_OS_MAC
