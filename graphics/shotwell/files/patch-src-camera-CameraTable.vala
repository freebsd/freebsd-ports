$NetBSD: patch-ab,v 1.4 2011/07/12 19:00:57 drochner Exp $

--- src/camera/CameraTable.vala.orig	2011-03-22 20:46:15.000000000 +0000
+++ src/camera/CameraTable.vala
@@ -26,7 +26,6 @@ public class CameraTable {
     
     private static CameraTable instance = null;
     
-    private GUdev.Client client = new GUdev.Client(SUBSYSTEMS);
     private OneShotScheduler camera_update_scheduler = null;
     private GPhoto.Context null_context = new GPhoto.Context();
     private GPhoto.CameraAbilitiesList abilities_list;
@@ -44,7 +43,6 @@ public class CameraTable {
             on_update_cameras);
         
         // listen for interesting events on the specified subsystems
-        client.uevent.connect(on_udev_event);
         volume_monitor = VolumeMonitor.get();
         volume_monitor.volume_changed.connect(on_volume_changed);
         volume_monitor.volume_added.connect(on_volume_changed);
@@ -96,43 +94,18 @@ public class CameraTable {
         if (res != GPhoto.Result.OK)
             throw new GPhotoError.LIBRARY("[%d] Unable to %s: %s", (int) res, op, res.as_string());
     }
-    
+
     private void init_camera_table() throws GPhotoError {
         do_op(GPhoto.CameraAbilitiesList.create(out abilities_list), "create camera abilities list");
         do_op(abilities_list.load(null_context), "load camera abilities list");
     }
-    
+
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
+
         return cameras;
     }
-    
+
     // USB (or libusb) is a funny beast; if only one USB device is present (i.e. the camera),
     // then a single camera is detected at port usb:.  However, if multiple USB devices are
     // present (including non-cameras), then the first attached camera will be listed twice,
@@ -141,59 +114,59 @@ public class CameraTable {
     //
     // This function gleans the full port name of a particular port, even if it's the unadorned
     // "usb:", by using GUdev.
-    private bool usb_esp(int current_camera_count, string[] usb_cameras, string port, 
+    private bool usb_esp(int current_camera_count, string[] usb_cameras, string port,
         out string full_port) {
         // sanity
         assert(current_camera_count > 0);
-        
+
         debug("USB ESP: current_camera_count=%d port=%s", current_camera_count, port);
-        
+
         // if GPhoto detects one camera, and USB reports one camera, all is swell
         if (current_camera_count == 1 && usb_cameras.length == 1) {
             full_port = usb_cameras[0];
-            
+
             debug("USB ESP: port=%s full_port=%s", port, full_port);
-            
+
             return true;
         }
 
         // with more than one camera, skip the mirrored "usb:" port
         if (port == "usb:") {
             debug("USB ESP: Skipping %s", port);
-            
+
             return false;
         }
-        
+
         // parse out the bus and device ID
         int bus, device;
         if (port.scanf("usb:%d,%d", out bus, out device) < 2) {
             critical("USB ESP: Failed to scanf %s", port);
-            
+
             return false;
         }
-        
+
         foreach (string usb_camera in usb_cameras) {
             int camera_bus, camera_device;
             if (usb_camera.scanf("usb:%d,%d", out camera_bus, out camera_device) < 2) {
                 critical("USB ESP: Failed to scanf %s", usb_camera);
-                
+
                 continue;
             }
-            
+
             if ((bus == camera_bus) && (device == camera_device)) {
                 full_port = port;
-                
+
                 debug("USB ESP: port=%s full_port=%s", port, full_port);
 
                 return true;
             }
         }
-        
+
         debug("USB ESP: No matching bus/device found for port=%s", port);
-        
+
         return false;
     }
-    
+
     public static string get_port_uri(string port) {
         return "gphoto2://[%s]/".printf(port);
     }
@@ -204,24 +177,6 @@ public class CameraTable {
             "/dev/bus/usb/%s".printf(port.substring(4).replace(",", "/")) : null;
     }
     
-    private string? get_name_for_uuid(string uuid) {
-        foreach (Volume volume in volume_monitor.get_volumes()) {
-            if (volume.get_identifier(VOLUME_IDENTIFIER_KIND_UUID) == uuid) {
-                return volume.get_name();
-            }
-        }
-        return null;
-    }
-    
-    private GLib.Icon? get_icon_for_uuid(string uuid) {
-        foreach (Volume volume in volume_monitor.get_volumes()) {
-            if (volume.get_identifier(VOLUME_IDENTIFIER_KIND_UUID) == uuid) {
-                return volume.get_icon();
-            }
-        }
-        return null;
-    }
-
     private void update_camera_table() throws GPhotoError {
         // need to do this because virtual ports come and go in the USB world (and probably others)
         GPhoto.PortInfoList port_info_list;
@@ -231,13 +186,13 @@ public class CameraTable {
         GPhoto.CameraList camera_list;
         do_op(GPhoto.CameraList.create(out camera_list), "create camera list");
         do_op(abilities_list.detect(port_info_list, camera_list, null_context), "detect cameras");
-        
+
         Gee.HashMap<string, string> detected_map = new Gee.HashMap<string, string>(str_hash, str_equal,
             str_equal);
-        
+
         // walk the USB chain and find all PTP cameras; this is necessary for usb_esp
         string[] usb_cameras = get_all_usb_cameras();
-        
+
         // go through the detected camera list and glean their ports
         for (int ctr = 0; ctr < camera_list.count(); ctr++) {
             string name;
@@ -245,55 +200,55 @@ public class CameraTable {
 
             string port;
             do_op(camera_list.get_value(ctr, out port), "get detected camera port");
-            
+
             debug("Detected %d/%d %s @ %s", ctr + 1, camera_list.count(), name, port);
-            
+
             // do some USB ESP, skipping ports that cannot be deduced
             if (port.has_prefix("usb:")) {
                 string full_port;
                 if (!usb_esp(camera_list.count(), usb_cameras, port, out full_port))
                     continue;
-                
+
                 port = full_port;
             }
 
             detected_map.set(port, name);
         }
-        
+
         // find cameras that have disappeared
         DiscoveredCamera[] missing = new DiscoveredCamera[0];
         foreach (DiscoveredCamera camera in camera_map.values) {
             GPhoto.PortInfo port_info;
-            do_op(camera.gcamera.get_port_info(out port_info), 
+            do_op(camera.gcamera.get_port_info(out port_info),
                 "retrieve missing camera port information");
-            
+
             GPhoto.CameraAbilities abilities;
             do_op(camera.gcamera.get_abilities(out abilities), "retrieve camera abilities");
-            
+
             if (detected_map.has_key(port_info.path)) {
                 debug("Found camera for %s @ %s in detected map", abilities.model, port_info.path);
-                
+
                 continue;
             }
-            
+
             debug("%s @ %s missing", abilities.model, port_info.path);
-            
+
             missing += camera;
         }
-        
+
         // have to remove from hash map outside of iterator
         foreach (DiscoveredCamera camera in missing) {
             GPhoto.PortInfo port_info;
             do_op(camera.gcamera.get_port_info(out port_info),
                 "retrieve missing camera port information");
-            
+
             GPhoto.CameraAbilities abilities;
             do_op(camera.gcamera.get_abilities(out abilities), "retrieve missing camera abilities");
 
             debug("Removing from camera table: %s @ %s", abilities.model, port_info.path);
 
             camera_map.unset(get_port_uri(port_info.path));
-            
+
             camera_removed(camera);
         }
 
@@ -311,23 +266,6 @@ public class CameraTable {
                 continue;
             }
             
-            // Get display name for camera.
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
             if (null == display_name) {
                 // Default to GPhoto detected name.
                 display_name = name;
@@ -365,13 +303,6 @@ public class CameraTable {
         }
     }
     
-    private void on_udev_event(string action, GUdev.Device device) {
-        debug("udev event: %s on %s", action, device.get_name());
-        
-        // Device add/removes often arrive in pairs; this allows for a single
-        // update to occur when they come in all at once
-        camera_update_scheduler.after_timeout(UPDATE_DELAY_MSEC, true);
-    }
     
     public void on_volume_changed(Volume volume) {
         camera_update_scheduler.after_timeout(UPDATE_DELAY_MSEC, true);
