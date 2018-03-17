--- src/camera/CameraTable.vala.orig	2018-03-10 06:42:15 UTC
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
@@ -107,36 +105,10 @@ public class CameraTable {
         do_op(GPhoto.CameraAbilitiesList.create(out abilities_list), "create camera abilities list");
         do_op(abilities_list.load(null_context), "load camera abilities list");
     }
-    
+
+    // dummy stub - the original requires udev
     private string[] get_all_usb_cameras() {
-        string[] cameras = new string[0];
-        
-        GLib.List<GUdev.Device> device_list = client.query_by_subsystem(null);
-        foreach (GUdev.Device device in device_list) {
-            string device_file = device.get_device_file();
-            if(
-                // only keep devices that have a non-null device file and that
-                // have both the ID_GPHOTO2 and GPHOTO2_DRIVER properties set
-                (device_file != null) &&
-                (device.has_property("ID_GPHOTO2")) &&
-                (device.has_property("GPHOTO2_DRIVER"))
-            ) {
-                int camera_bus, camera_device;
-                // extract the bus and device IDs from the device file string
-                // TODO: is it safe to parse the absolute path or should we be
-                // smarter and use a regex to only pick up the end of the path?
-                if (device_file.scanf("/dev/bus/usb/%d/%d", out camera_bus, out camera_device) < 2) {
-                    critical("get_all_usb_cameras: Failed to scanf device file %s", device_file);
-                    
-                    continue;
-                }
-                string camera = "usb:%.3d,%.3d".printf(camera_bus, camera_device);
-                debug("USB camera detected at %s", camera);
-                cameras += camera;
-            }
-        }
-        
-        return cameras;
+        return new string[0];
     }
     
     // USB (or libusb) is a funny beast; if only one USB device is present (i.e. the camera),
@@ -211,24 +183,8 @@ public class CameraTable {
         return port.has_prefix("usb:") ? 
             "/dev/bus/usb/%s".printf(port.substring(4).replace(",", "/")) : null;
     }
-    
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
+ 
+    // get_name_for_uuid() and get_icon_for_uuid() are not used (udev removal)
 
     private void update_camera_table() throws GPhotoError {
         // need to do this because virtual ports come and go in the USB world (and probably others)
@@ -326,23 +282,7 @@ public class CameraTable {
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
@@ -391,14 +331,8 @@ public class CameraTable {
             camera_added(camera);
         }
     }
-    
-    private void on_udev_event(string action, GUdev.Device device) {
-        debug("udev event: %s on %s", action, device.get_name());
-        
-        // Device add/removes often arrive in pairs; this allows for a single
-        // update to occur when they come in all at once
-        camera_update_scheduler.after_timeout(UPDATE_DELAY_MSEC, true);
-    }
+
+    // on_udev_event() removed - we do not have udev
     
     public void on_volume_changed(Volume volume) {
         camera_update_scheduler.after_timeout(UPDATE_DELAY_MSEC, true);
