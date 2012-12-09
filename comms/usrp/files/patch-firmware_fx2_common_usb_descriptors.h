--- firmware/fx2/common/usb_descriptors.h.orig	2012-07-30 14:09:48.000000000 -0500
+++ firmware/fx2/common/usb_descriptors.h	2012-10-07 19:36:22.000000000 -0500
@@ -20,21 +20,21 @@
  * Boston, MA 02110-1301, USA.
  */
 
-extern xdata const char high_speed_device_descr[];
-extern xdata const char high_speed_devqual_descr[];
-extern xdata const char high_speed_config_descr[];
+extern __xdata const char high_speed_device_descr[];
+extern __xdata const char high_speed_devqual_descr[];
+extern __xdata const char high_speed_config_descr[];
 
-extern xdata const char full_speed_device_descr[];
-extern xdata const char full_speed_devqual_descr[];
-extern xdata const char full_speed_config_descr[];
+extern __xdata const char full_speed_device_descr[];
+extern __xdata const char full_speed_devqual_descr[];
+extern __xdata const char full_speed_config_descr[];
 
-extern xdata unsigned char nstring_descriptors;
-extern xdata char * xdata string_descriptors[];
+extern __xdata unsigned char nstring_descriptors;
+extern __xdata char * __xdata string_descriptors[];
 
 /*
  * We patch these locations with info read from the usrp config eeprom
  */
-extern xdata char usb_desc_hw_rev_binary_patch_location_0[];
-extern xdata char usb_desc_hw_rev_binary_patch_location_1[];
-extern xdata char usb_desc_hw_rev_ascii_patch_location_0[];
-extern xdata char usb_desc_serial_number_ascii[];
+extern __xdata char usb_desc_hw_rev_binary_patch_location_0[];
+extern __xdata char usb_desc_hw_rev_binary_patch_location_1[];
+extern __xdata char usb_desc_hw_rev_ascii_patch_location_0[];
+extern __xdata char usb_desc_serial_number_ascii[];
