Disable hotplug support for FreeBSD

--- Source/Core/Core/HW/SI_GCAdapter.cpp.orig	2015-10-09 20:50:29.920884454 +0000
+++ Source/Core/Core/HW/SI_GCAdapter.cpp	2015-10-09 20:53:25.933872616 +0000
@@ -49,7 +49,9 @@
 static bool s_libusb_driver_not_supported = false;
 static libusb_context* s_libusb_context = nullptr;
 static bool s_libusb_hotplug_enabled = false;
+#if !defined(__FreeBSD__)
 static libusb_hotplug_callback_handle s_hotplug_handle;
+#endif
 
 static u8 s_endpoint_in = 0;
 static u8 s_endpoint_out = 0;
@@ -71,6 +73,7 @@
 	}
 }
 
+#if !defined(__FreeBSD__)
 static int HotplugCallback(libusb_context* ctx, libusb_device* dev, libusb_hotplug_event event, void* user_data)
 {
 	if (event == LIBUSB_HOTPLUG_EVENT_DEVICE_ARRIVED)
@@ -85,12 +88,14 @@
 	}
 	return 0;
 }
+#endif
 
 static void ScanThreadFunc()
 {
 	Common::SetCurrentThreadName("GC Adapter Scanning Thread");
 	NOTICE_LOG(SERIALINTERFACE, "GC Adapter scanning thread started");
 
+#if !defined(__FreeBSD__)
 	s_libusb_hotplug_enabled = libusb_has_capability(LIBUSB_CAP_HAS_HOTPLUG) != 0;
 	if (s_libusb_hotplug_enabled)
 	{
@@ -99,6 +104,7 @@
 		if (s_libusb_hotplug_enabled)
 			NOTICE_LOG(SERIALINTERFACE, "Using libUSB hotplug detection");
 	}
+#endif
 
 	while (s_adapter_detect_thread_running.IsSet())
 	{
@@ -298,8 +304,10 @@
 void Shutdown()
 {
 	StopScanThread();
+#if !defined(__FreeBSD__)
 	if (s_libusb_hotplug_enabled)
 		libusb_hotplug_deregister_callback(s_libusb_context, s_hotplug_handle);
+#endif
 	Reset();
 
 	if (s_libusb_context)
