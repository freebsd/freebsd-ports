--- src/camera/CameraTable.vala.orig	2018-07-15 15:10:47 UTC
+++ src/camera/CameraTable.vala
@@ -26,7 +26,6 @@ public class CameraTable {
     
     private static CameraTable instance = null;
     
-    private GUdev.Client client = new GUdev.Client(SUBSYSTEMS);
     private OneShotScheduler camera_update_scheduler = null;
     private GPhoto.Context null_context = new GPhoto.Context();
     private GPhoto.CameraAbilitiesList abilities_list;
@@ -43,7 +42,6 @@ public class CameraTable {
             on_update_cameras);
         
         // listen for interesting events on the specified subsystems
-        client.uevent.connect(on_udev_event);
         volume_monitor = VolumeMonitor.get();
         volume_monitor.volume_changed.connect(on_volume_changed);
         volume_monitor.volume_added.connect(on_volume_changed);
@@ -118,23 +116,7 @@ public class CameraTable {
             "/dev/bus/usb/%s".printf(port.substring(4).replace(",", "/")) : null;
     }
     
-    private string? get_name_for_uuid(string uuid) {
-        foreach (Volume volume in volume_monitor.get_volumes()) {
-            if (volume.get_identifier(VolumeIdentifier.UUID) == uuid) {
-                return volume.get_name();
-            }
-        }
-        return null;
-    }
-    
-    private string? get_icon_for_uuid(string uuid) {
-        foreach (Volume volume in volume_monitor.get_volumes()) {
-            if (volume.get_identifier(VolumeIdentifier.UUID) == uuid) {
-                return volume.get_icon().to_string();
-            }
-        }
-        return null;
-    }
+    // get_name_for_uuid() and get_icon_for_uuid() are not used (udev removal)
 
     private void update_camera_table() throws GPhotoError {
         // need to do this because virtual ports come and go in the USB world (and probably others)
@@ -221,23 +203,7 @@ public class CameraTable {
             }
             
             // Get display name for camera.
-            string path = get_port_path(port);
-            if (null != path) {
-                GUdev.Device device = client.query_by_device_file(path);
-                string serial = device.get_property("ID_SERIAL_SHORT");
-                if (null != serial) {
-                    // Try to get the name and icon.
-                    display_name = get_name_for_uuid(serial);
-                    icon = get_icon_for_uuid(serial);
-                }
-                if (null == display_name) {
-                    display_name = device.get_sysfs_attr("product");
-                } 
-                if (null == display_name) {
-                    display_name = device.get_property("ID_MODEL");
-                }
-            }
-
+            // in absence of udev, we fall back to the GPhoto name
             if (port.has_prefix("disk:")) {
                 try {
                     var mount = File.new_for_path (port.substring(5)).find_enclosing_mount();
@@ -287,13 +253,7 @@ public class CameraTable {
         }
     }
     
-    private void on_udev_event(string action, GUdev.Device device) {
-        debug("udev event: %s on %s", action, device.get_name());
-        
-        // Device add/removes often arrive in pairs; this allows for a single
-        // update to occur when they come in all at once
-        camera_update_scheduler.after_timeout(UPDATE_DELAY_MSEC, true);
-    }
+    // on_udev_event() removed - we do not have udev
     
     public void on_volume_changed(Volume volume) {
         camera_update_scheduler.after_timeout(UPDATE_DELAY_MSEC, true);
