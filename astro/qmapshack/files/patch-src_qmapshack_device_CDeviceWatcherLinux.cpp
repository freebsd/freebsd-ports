--- src/qmapshack/device/CDeviceWatcherLinux.cpp.orig	2023-07-20 14:13:59 UTC
+++ src/qmapshack/device/CDeviceWatcherLinux.cpp
@@ -47,6 +47,10 @@ void CDeviceWatcherLinux::slotDeviceAdded(const QDBusO
   QDBusInterface* blockIface = new QDBusInterface("org.freedesktop.UDisks2", path.path(),
                                                   "org.freedesktop.UDisks2.Block", QDBusConnection::systemBus(), this);
   QDBusObjectPath drive_object = blockIface->property("Drive").value<QDBusObjectPath>();
+  if(drive_object.path() == nullptr)
+  {
+    return;
+  }
   QString idLabel = blockIface->property("IdLabel").toString().toUpper();
 
   // read vendor string attached to drive
