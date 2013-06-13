--- ./src/camera/CameraTable.vala.orig	2013-04-20 21:27:30.000000000 +0200
+++ ./src/camera/CameraTable.vala	2013-04-20 21:31:02.000000000 +0200
@@ -26,7 +26,6 @@
     
     private static CameraTable instance = null;
     
-    private GUdev.Client client = new GUdev.Client(SUBSYSTEMS);
     private OneShotScheduler camera_update_scheduler = null;
     private GPhoto.Context null_context = new GPhoto.Context();
     private GPhoto.CameraAbilitiesList abilities_list;
@@ -44,7 +43,6 @@
             on_update_cameras);
         
         // listen for interesting events on the specified subsystems
-        client.uevent.connect(on_udev_event);
         volume_monitor = VolumeMonitor.get();
         volume_monitor.volume_changed.connect(on_volume_changed);
         volume_monitor.volume_added.connect(on_volume_changed);
@@ -111,32 +109,7 @@
     
     private string[] get_all_usb_cameras() {
         string[] cameras = new string[0];
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
+		// this would require udev, so we'll just return an empty array
         return cameras;
     }
     
@@ -213,23 +186,7 @@
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
-    private GLib.Icon? get_icon_for_uuid(string uuid) {
-        foreach (Volume volume in volume_monitor.get_volumes()) {
-            if (volume.get_identifier(VolumeIdentifier.UUID) == uuid) {
-                return volume.get_icon();
-            }
-        }
-        return null;
-    }
+	// get_name_for_uuid() and get_icon_for_uuid() are not used (udev removal)
 
     private void update_camera_table() throws GPhotoError {
         // need to do this because virtual ports come and go in the USB world (and probably others)
@@ -336,22 +293,7 @@
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
+			// we use a default name, as everything else requires udev
             if (null == display_name) {
                 // Default to GPhoto detected name.
                 display_name = name;
@@ -396,13 +338,7 @@
         }
     }
     
-    private void on_udev_event(string action, GUdev.Device device) {
-        debug("udev event: %s on %s", action, device.get_name());
-        
-        // Device add/removes often arrive in pairs; this allows for a single
-        // update to occur when they come in all at once
-        camera_update_scheduler.after_timeout(UPDATE_DELAY_MSEC, true);
-    }
+	// on_udev_event() removed as "udev related"
     
     public void on_volume_changed(Volume volume) {
         camera_update_scheduler.after_timeout(UPDATE_DELAY_MSEC, true);
