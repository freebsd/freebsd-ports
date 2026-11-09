--- heimdall/source/BridgeManager.cpp.orig	2026-11-06 00:00:00 UTC
+++ heimdall/source/BridgeManager.cpp
@@ -480,8 +480,10 @@
 		return (BridgeManager::kInitialiseFailed);
 	}
 
+#if LIBUSBX_VERSION_HEX >= 0x01000207 /* libusb_set_option() added in 1.0.27 */
 	// Fixes LIBUSB_ERROR_NOT_FOUND when using dg_ssudbus driver instead of WinUSB.
 	libusb_set_option(libusbContext, LIBUSB_OPTION_USE_USBDK);
+#endif
 
 	// Setup libusb log level.
 	SetUsbLogLevel(usbLogLevel);
@@ -1246,23 +1248,43 @@
 		switch (usbLogLevel)
 		{
 			case UsbLogLevel::None:
+#if LIBUSBX_VERSION_HEX >= 0x01000207 /* libusb_set_option() added in 1.0.27 */
 				libusb_set_option(libusbContext, LIBUSB_OPTION_LOG_LEVEL, LIBUSB_LOG_LEVEL_NONE);
+#else
+				libusb_set_debug(libusbContext, LIBUSB_LOG_LEVEL_NONE);
+#endif
 				break;
 
 			case UsbLogLevel::Error:
+#if LIBUSBX_VERSION_HEX >= 0x01000207 /* libusb_set_option() added in 1.0.27 */
 				libusb_set_option(libusbContext, LIBUSB_OPTION_LOG_LEVEL, LIBUSB_LOG_LEVEL_ERROR);
+#else
+				libusb_set_debug(libusbContext, LIBUSB_LOG_LEVEL_ERROR);
+#endif
 				break;
 
 			case UsbLogLevel::Warning:
+#if LIBUSBX_VERSION_HEX >= 0x01000207 /* libusb_set_option() added in 1.0.27 */
 				libusb_set_option(libusbContext, LIBUSB_OPTION_LOG_LEVEL, LIBUSB_LOG_LEVEL_WARNING);
+#else
+				libusb_set_debug(libusbContext, LIBUSB_LOG_LEVEL_WARNING);
+#endif
 				break;
 
 			case UsbLogLevel::Info:
+#if LIBUSBX_VERSION_HEX >= 0x01000207 /* libusb_set_option() added in 1.0.27 */
 				libusb_set_option(libusbContext, LIBUSB_OPTION_LOG_LEVEL, LIBUSB_LOG_LEVEL_INFO);
+#else
+				libusb_set_debug(libusbContext, LIBUSB_LOG_LEVEL_INFO);
+#endif
 				break;
 
 			case UsbLogLevel::Debug:
+#if LIBUSBX_VERSION_HEX >= 0x01000207 /* libusb_set_option() added in 1.0.27 */
 				libusb_set_option(libusbContext, LIBUSB_OPTION_LOG_LEVEL, LIBUSB_LOG_LEVEL_DEBUG);
+#else
+				libusb_set_debug(libusbContext, LIBUSB_LOG_LEVEL_DEBUG);
+#endif
 				break;
 		}
 	}
