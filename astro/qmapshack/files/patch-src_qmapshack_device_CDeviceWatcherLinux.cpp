--- src/qmapshack/device/CDeviceWatcherLinux.cpp.orig	2025-07-04 12:38:57 UTC
+++ src/qmapshack/device/CDeviceWatcherLinux.cpp
@@ -97,6 +97,10 @@ void CDeviceWatcherLinux::slotDeviceAdded(const QDBusO
   QDBusInterface* blockIface = new QDBusInterface("org.freedesktop.UDisks2", path.path(),
                                                   "org.freedesktop.UDisks2.Block", QDBusConnection::systemBus(), this);
   QDBusObjectPath drive_object = blockIface->property("Drive").value<QDBusObjectPath>();
+  if(drive_object.path() == nullptr)
+  {
+    return;
+  }
   QString idLabel = blockIface->property("IdLabel").toString().toUpper();
 
   // read vendor string attached to drive
@@ -207,14 +211,6 @@ QString CDeviceWatcherLinux::readMountPoint(const QStr
 
   const QDBusMessage& reply = QDBusConnection::systemBus().call(message);
 
-#if defined(Q_OS_FREEBSD)
-  // this is probably broken code and needs to be fixed
-  for (const QVariant& arg : reply.arguments()) {
-    if (!arg.value<QDBusVariant>().variant().value<QStringList>().isEmpty()) {
-      points.append(arg.value<QDBusVariant>().variant().value<QStringList>().first());
-    }
-  }
-#else
   QStringList mountPoints;
 
   for (const QVariant& arg : reply.arguments()) {
@@ -246,7 +242,6 @@ QString CDeviceWatcherLinux::readMountPoint(const QStr
     }
     dbusArg.endArray();
   }
-#endif
 
   if (!mountPoints.isEmpty()) {
     return mountPoints.first();
