--- kstars/auxiliary/ksutils.cpp.orig	2019-09-09 16:36:17 UTC
+++ kstars/auxiliary/ksutils.cpp
@@ -1325,7 +1325,7 @@ bool copyRecursively(QString sourceFolder, QString des
 //One is createLocalAstrometryConf and the other is configureAstrometry
 bool configureLocalAstrometryConfIfNecessary()
 {
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
     QString confPath = KSPaths::writableLocation(QStandardPaths::GenericDataLocation) + QLatin1Literal("astrometry") + QLatin1Literal("/astrometry.cfg");
     if (QFileInfo(confPath).exists() == false)
     {
