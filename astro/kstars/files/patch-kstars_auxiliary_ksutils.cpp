--- kstars/auxiliary/ksutils.cpp.orig	2019-09-08 19:12:11 UTC
+++ kstars/auxiliary/ksutils.cpp
@@ -1323,7 +1323,7 @@ bool copyRecursively(QString sourceFolder, QString des
 //One is createLocalAstrometryConf and the other is configureAstrometry
 bool configureLocalAstrometryConfIfNecessary()
 {
-#if defined(Q_OS_LINUX)
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
     QString confPath = KSPaths::writableLocation(QStandardPaths::GenericDataLocation) + QLatin1Literal("astrometry") + QLatin1Literal("/astrometry.cfg");
     if (QFileInfo(confPath).exists() == false)
     {
