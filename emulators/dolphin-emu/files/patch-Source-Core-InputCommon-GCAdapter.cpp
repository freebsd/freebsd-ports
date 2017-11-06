commit c5b3b52d553d
Author: Jeffrey Pfau <jeffrey@endrift.com>
Date:   Mon Dec 26 22:50:36 2016 -0800

    InputCommon: Fix FreeBSD 11 libusb incompatibilities
---
 Source/Core/InputCommon/GCAdapter.cpp | 6 ++++++
 1 file changed, 6 insertions(+)

--- Source/Core/InputCommon/GCAdapter.cpp.orig	2016-06-24 08:09:07 UTC
+++ Source/Core/InputCommon/GCAdapter.cpp
@@ -49,7 +49,11 @@ static std::function<void(void)> s_detect_callback;
 
 static bool s_libusb_driver_not_supported = false;
 static libusb_context* s_libusb_context = nullptr;
+#if defined(__FreeBSD__) && __FreeBSD__ >= 11
+static bool s_libusb_hotplug_enabled = true;
+#else
 static bool s_libusb_hotplug_enabled = false;
+#endif
 #if defined(LIBUSB_API_VERSION) && LIBUSB_API_VERSION >= 0x01000102
 static libusb_hotplug_callback_handle s_hotplug_handle;
 #endif
@@ -102,7 +106,9 @@ static void ScanThreadFunc()
 	NOTICE_LOG(SERIALINTERFACE, "GC Adapter scanning thread started");
 
 #if defined(LIBUSB_API_VERSION) && LIBUSB_API_VERSION >= 0x01000102
+#ifndef __FreeBSD__
 	s_libusb_hotplug_enabled = libusb_has_capability(LIBUSB_CAP_HAS_HOTPLUG) != 0;
+#endif
 	if (s_libusb_hotplug_enabled)
 	{
 		if (libusb_hotplug_register_callback(s_libusb_context, (libusb_hotplug_event)(LIBUSB_HOTPLUG_EVENT_DEVICE_ARRIVED | LIBUSB_HOTPLUG_EVENT_DEVICE_LEFT), LIBUSB_HOTPLUG_ENUMERATE, 0x057e, 0x0337, LIBUSB_HOTPLUG_MATCH_ANY, HotplugCallback, nullptr, &s_hotplug_handle) != LIBUSB_SUCCESS)
