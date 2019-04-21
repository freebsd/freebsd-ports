--- src/qmapshack/device/CDeviceWatcherLinux.cpp.orig	2019-04-20 21:33:23.749597000 +0200
+++ src/qmapshack/device/CDeviceWatcherLinux.cpp	2019-04-20 21:34:05.021101000 +0200
@@ -174,7 +174,9 @@
 #if defined(Q_OS_FREEBSD)
     for(const QVariant &arg : reply.arguments())
     {
-        points.append(arg.value<QDBusVariant>().variant().value<QStringList>().first());
+        if(!arg.value<QDBusVariant>().variant().value<QStringList>().isEmpty()) {
+            points.append(arg.value<QDBusVariant>().variant().value<QStringList>().first());
+        }
     }
 #else
     QList<QByteArray> list;
