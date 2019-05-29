Avoid crashing when udev_device_get_parent() returns a NULL pointer

Backport from commit 66e6afb

--- src/Input/FGLinuxEventInput.cxx.orig
+++ src/Input/FGLinuxEventInput.cxx
@@ -481,13 +481,15 @@ void FGLinuxEventInput::postinit()
     struct udev_device *dev = udev_device_new_from_syspath(udev, path);
     const char * node = udev_device_get_devnode(dev);
  
-    dev = udev_device_get_parent( dev );
-    const char * name = udev_device_get_sysattr_value(dev,"name");
-    const char * serial = udev_device_get_sysattr_value(dev, "serial");
-    SG_LOG(SG_INPUT,SG_DEBUG, "name=" << (name?name:"<null>") << ", node=" << (node?node:"<null>"));
-    if( name && node ) {
-      std::string serialString = serial ? serial : std::string{};
-      AddDevice( new FGLinuxInputDevice(name, node, serialString) );
+    struct udev_device * parent_dev = udev_device_get_parent( dev );
+    if ( parent_dev != NULL ) {
+      const char * name = udev_device_get_sysattr_value(parent_dev,"name");
+      const char * serial = udev_device_get_sysattr_value(parent_dev, "serial");
+      SG_LOG(SG_INPUT,SG_DEBUG, "name=" << (name?name:"<null>") << ", node=" << (node?node:"<null>"));
+      if( name && node ) {
+        std::string serialString = serial ? serial : std::string{};
+        AddDevice( new FGLinuxInputDevice(name, node, serialString) );
+      }
     }
 
     udev_device_unref(dev);
