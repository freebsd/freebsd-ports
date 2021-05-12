--- ui/events/keycodes/dom/keycode_converter.cc.orig	2021-04-14 01:09:39 UTC
+++ ui/events/keycodes/dom/keycode_converter.cc
@@ -24,7 +24,7 @@ namespace {
 #if defined(OS_WIN)
 #define DOM_CODE(usb, evdev, xkb, win, mac, code, id) \
   { usb, win, code }
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #define DOM_CODE(usb, evdev, xkb, win, mac, code, id) \
   { usb, xkb, code }
 #elif defined(OS_APPLE)
