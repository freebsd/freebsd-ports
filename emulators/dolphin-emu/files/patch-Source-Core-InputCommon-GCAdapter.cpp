--- Source/Core/InputCommon/GCAdapter.cpp.orig	2016-12-01 10:27:29.504018310 +0000
+++ Source/Core/InputCommon/GCAdapter.cpp	2016-12-01 10:30:44.024005984 +0000
@@ -50,7 +50,7 @@
 static bool s_libusb_driver_not_supported = false;
 static libusb_context* s_libusb_context = nullptr;
 static bool s_libusb_hotplug_enabled = false;
-#if defined(LIBUSB_API_VERSION) && LIBUSB_API_VERSION >= 0x01000102
+#if !defined(__FreeBSD__) && defined(LIBUSB_API_VERSION) && LIBUSB_API_VERSION >= 0x01000102
 static libusb_hotplug_callback_handle s_hotplug_handle;
 #endif
 
@@ -76,7 +76,7 @@
 	}
 }
 
-#if defined(LIBUSB_API_VERSION) && LIBUSB_API_VERSION >= 0x01000102
+#if !defined(__FreeBSD__) && defined(LIBUSB_API_VERSION) && LIBUSB_API_VERSION >= 0x01000102
 static int HotplugCallback(libusb_context* ctx, libusb_device* dev, libusb_hotplug_event event, void* user_data)
 {
 	if (event == LIBUSB_HOTPLUG_EVENT_DEVICE_ARRIVED)
@@ -101,7 +101,7 @@
 	Common::SetCurrentThreadName("GC Adapter Scanning Thread");
 	NOTICE_LOG(SERIALINTERFACE, "GC Adapter scanning thread started");
 
-#if defined(LIBUSB_API_VERSION) && LIBUSB_API_VERSION >= 0x01000102
+#if !defined(__FreeBSD__) && defined(LIBUSB_API_VERSION) && LIBUSB_API_VERSION >= 0x01000102
 	s_libusb_hotplug_enabled = libusb_has_capability(LIBUSB_CAP_HAS_HOTPLUG) != 0;
 	if (s_libusb_hotplug_enabled)
 	{
@@ -321,7 +321,7 @@
 void Shutdown()
 {
 	StopScanThread();
-#if defined(LIBUSB_API_VERSION) && LIBUSB_API_VERSION >= 0x01000102
+#if !defined(__FreeBSD__) && defined(LIBUSB_API_VERSION) && LIBUSB_API_VERSION >= 0x01000102
 	if (s_libusb_hotplug_enabled)
 		libusb_hotplug_deregister_callback(s_libusb_context, s_hotplug_handle);
 #endif
