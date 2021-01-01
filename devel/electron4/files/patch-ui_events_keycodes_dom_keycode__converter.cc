--- ui/events/keycodes/dom/keycode_converter.cc.orig	2019-03-15 06:38:27 UTC
+++ ui/events/keycodes/dom/keycode_converter.cc
@@ -20,7 +20,7 @@ namespace {
 // and DOM Level 3 |code| strings.
 #if defined(OS_WIN)
 #define USB_KEYMAP(usb, evdev, xkb, win, mac, code, id) {usb, win, code}
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #define USB_KEYMAP(usb, evdev, xkb, win, mac, code, id) {usb, xkb, code}
 #elif defined(OS_MACOSX)
 #define USB_KEYMAP(usb, evdev, xkb, win, mac, code, id) {usb, mac, code}
