--- lib/hidapi-0.8.0-rc1/libusb/hid.c.orig	2015-12-29 16:10:41 UTC
+++ lib/hidapi-0.8.0-rc1/libusb/hid.c
@@ -258,7 +258,7 @@ static int get_usage(uint8_t *report_des
    Note that the data parameter is Unicode in UTF-16LE encoding.
    Return value is the number of bytes in data, or LIBUSB_ERROR_*.
  */
-static inline int libusb_get_string_descriptor(libusb_device_handle *dev,
+inline int libusb_get_string_descriptor(libusb_device_handle *dev,
 	uint8_t descriptor_index, uint16_t lang_id,
 	unsigned char *data, int length)
 {
