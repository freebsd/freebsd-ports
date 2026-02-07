--- src/hidapi/SDL_hidapi.c.orig	2025-03-04 22:37:06 UTC
+++ src/hidapi/SDL_hidapi.c
@@ -710,7 +710,7 @@ static struct
     );
     void (LIBUSB_CALL *free_config_descriptor)(struct libusb_config_descriptor *config);
     uint8_t (LIBUSB_CALL *get_bus_number)(libusb_device *dev);
-    int (LIBUSB_CALL *get_port_numbers)(libusb_device *dev, uint8_t *port_numbers, int port_numbers_len);
+    int (LIBUSB_CALL *get_port_numbers)(libusb_device *dev, uint8_t *port_numbers, uint8_t port_numbers_len);
     uint8_t (LIBUSB_CALL *get_device_address)(libusb_device *dev);
     int (LIBUSB_CALL *open)(libusb_device *dev, libusb_device_handle **dev_handle);
     void (LIBUSB_CALL *close)(libusb_device_handle *dev_handle);
@@ -1188,7 +1188,7 @@ int SDL_hid_init(void)
             LOAD_LIBUSB_SYMBOL(int (LIBUSB_CALL *)(libusb_device *, uint8_t, struct libusb_config_descriptor **), get_config_descriptor)
             LOAD_LIBUSB_SYMBOL(void (LIBUSB_CALL *)(struct libusb_config_descriptor *), free_config_descriptor)
             LOAD_LIBUSB_SYMBOL(uint8_t (LIBUSB_CALL *)(libusb_device *), get_bus_number)
-            LOAD_LIBUSB_SYMBOL(int (LIBUSB_CALL *)(libusb_device *dev, uint8_t *port_numbers, int port_numbers_len), get_port_numbers)
+            LOAD_LIBUSB_SYMBOL(int (LIBUSB_CALL *)(libusb_device *dev, uint8_t *port_numbers, uint8_t port_numbers_len), get_port_numbers)
             LOAD_LIBUSB_SYMBOL(uint8_t (LIBUSB_CALL *)(libusb_device *), get_device_address)
             LOAD_LIBUSB_SYMBOL(int (LIBUSB_CALL *)(libusb_device *, libusb_device_handle **), open)
             LOAD_LIBUSB_SYMBOL(void (LIBUSB_CALL *)(libusb_device_handle *), close)
