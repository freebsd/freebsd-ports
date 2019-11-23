--- src/qmapshack/device/CDeviceWatcherLinux.cpp.orig	2019-11-01 16:47:46 UTC
+++ src/qmapshack/device/CDeviceWatcherLinux.cpp
@@ -58,6 +58,10 @@ void CDeviceWatcherLinux::slotDeviceAdded(const QDBusO
     // create path of to drive the block device belongs to
     QDBusInterface * blockIface = new QDBusInterface("org.freedesktop.UDisks2", path.path(), "org.freedesktop.UDisks2.Block", QDBusConnection::systemBus(), this);
     QDBusObjectPath drive_object = blockIface->property("Drive").value<QDBusObjectPath>();
+    if(drive_object.path() == nullptr)
+    {
+        return;
+    }
     QString idLabel = blockIface->property("IdLabel").toString().toUpper();
 
     // read vendor string attached to drive
