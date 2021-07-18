--- src/diskdriveinfo.cpp.orig	2021-02-19 10:07:38 UTC
+++ src/diskdriveinfo.cpp
@@ -3,6 +3,10 @@
 #include <QString>
 #include <QFile>
 #include <QFileInfo>
+#ifdef __FreeBSD__
+#include <sys/disk.h>
+#include <sys/fcntl.h>
+#endif
 
 QString DiskDriveInfo::getDeviceByVolume(const QString &volume)
 {
@@ -12,6 +16,7 @@ QString DiskDriveInfo::getDeviceByVolume(const QString
 
 QString DiskDriveInfo::getModelName(const QString &volume)
 {
+#if defined(__linux__)
     QFileInfo sysClass(QFileInfo(QString("/sys/class/block/%1/..")
                                  .arg(getDeviceByVolume(volume)))
                        .canonicalFilePath());
@@ -24,7 +29,18 @@ QString DiskDriveInfo::getModelName(const QString &vol
     QString model = sysBlock.readAll().simplified();
 
     sysBlock.close();
+#elif defined(__FreeBSD__)
+    struct diocgattr_arg arg;
 
+    strlcpy(arg.name, "GEOM::descr", sizeof(arg.name));
+    arg.len = sizeof(arg.value.str);
+
+    int fd = open(volume.toStdString().c_str(), O_RDONLY);
+    if (fd == -1 || ioctl(fd, DIOCGATTR, &arg) == -1)
+        return QString();
+
+    QString model(arg.value.str);
+#endif
     return model;
 }
 
