--- a/hw/usb/host-libusb.c
+++ b/hw/usb/host-libusb.c
@@ -1324,8 +1324,12 @@ static Property usb_host_dev_properties[
     DEFINE_PROP_UINT32("isobufs",  USBHostDevice, iso_urb_count,    4),
     DEFINE_PROP_UINT32("isobsize", USBHostDevice, iso_urb_frames,   32),
     DEFINE_PROP_INT32("bootindex", USBHostDevice, bootindex,        -1),
+#ifdef LIBUSB_LOG_LEVEL_WARNING
     DEFINE_PROP_UINT32("loglevel",  USBHostDevice, loglevel,
                        LIBUSB_LOG_LEVEL_WARNING),
+#else
+    DEFINE_PROP_UINT32("loglevel",  USBHostDevice, loglevel, 0),
+#endif
     DEFINE_PROP_BIT("pipeline",    USBHostDevice, options,
                     USB_HOST_OPT_PIPELINE, true),
     DEFINE_PROP_END_OF_LIST(),
