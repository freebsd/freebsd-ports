--- kstars/auxiliary/ksutils.cpp.orig	2019-11-07 16:33:51 UTC
+++ kstars/auxiliary/ksutils.cpp
@@ -1419,7 +1419,7 @@ bool createLocalAstrometryConf()
 
 QString getAstrometryConfFilePath()
 {
-#if defined(Q_OS_LINUX)
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
     if (Options::astrometryConfFileIsInternal())
         return KSPaths::writableLocation(QStandardPaths::GenericDataLocation) + QLatin1String("astrometry") + QLatin1String("/astrometry.cfg");
 #elif defined(Q_OS_OSX)
