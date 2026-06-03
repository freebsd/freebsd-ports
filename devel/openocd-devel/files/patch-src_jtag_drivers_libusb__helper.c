--- src/jtag/drivers/libusb_helper.c.orig	2025-09-13 12:06:50 UTC
+++ src/jtag/drivers/libusb_helper.c
@@ -378,6 +378,24 @@ int jtag_libusb_handle_events_completed(int *completed
 	return libusb_handle_events_completed(jtag_libusb_context, completed);
 }
 
+#if __FreeBSD__ >= 15
+uint8_t *oocd_libusb_dev_mem_alloc(libusb_device_handle *devh,
+			size_t length)
+{
+	return malloc(length);
+}
+
+int oocd_libusb_dev_mem_free(libusb_device_handle *devh,
+		uint8_t *buffer, size_t length)
+{
+	if (!buffer)
+		return ERROR_OK;
+
+	free(buffer);
+	return ERROR_OK;
+}
+#else
+
 static enum {
 	DEV_MEM_NOT_YET_DECIDED,
 	DEV_MEM_AVAILABLE,
@@ -433,3 +451,4 @@ int oocd_libusb_dev_mem_free(libusb_device_handle *dev
 	}
 	return ERROR_FAIL;
 }
+#endif
