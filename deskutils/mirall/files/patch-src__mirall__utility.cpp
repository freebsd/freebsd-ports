--- ./src/mirall/utility.cpp.orig	2013-09-04 11:09:12.000000000 +0200
+++ ./src/mirall/utility.cpp	2013-09-18 15:01:54.000000000 +0200
@@ -313,7 +313,7 @@
 
 qint64 Utility::freeDiskSpace(const QString &path, bool *ok)
 {
-#ifdef Q_OS_MAC
+#if defined(Q_OS_MAC) || defined(Q_OS_FREEBSD)
     struct statvfs stat;
     statvfs(path.toUtf8().data(), &stat);
     return (qint64) stat.f_bavail * stat.f_frsize;
