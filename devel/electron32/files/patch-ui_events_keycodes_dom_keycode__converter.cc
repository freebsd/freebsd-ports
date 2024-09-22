--- ui/events/keycodes/dom/keycode_converter.cc.orig	2024-06-18 21:44:02 UTC
+++ ui/events/keycodes/dom/keycode_converter.cc
@@ -13,7 +13,7 @@
 #include "ui/events/keycodes/dom/dom_code.h"
 #include "ui/events/keycodes/dom/dom_key.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FREEBSD)
 #include <linux/input.h>
 #endif
 
@@ -26,7 +26,7 @@ namespace {
 #if BUILDFLAG(IS_WIN)
 #define DOM_CODE(usb, evdev, xkb, win, mac, code, id) \
   { usb, win, code }
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #define DOM_CODE(usb, evdev, xkb, win, mac, code, id) \
   { usb, xkb, code }
 #elif BUILDFLAG(IS_APPLE)
@@ -65,7 +65,7 @@ struct DomKeyMapEntry {
 #undef DOM_KEY_UNI
 #undef DOM_KEY_MAP_DECLARATION_END
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FREEBSD)
 
 // The offset between XKB Keycode and evdev code.
 constexpr int kXkbKeycodeOffset = 8;
@@ -186,7 +186,7 @@ int KeycodeConverter::DomCodeToNativeKeycode(DomCode c
   return UsbKeycodeToNativeKeycode(static_cast<uint32_t>(code));
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FREEBSD)
 // static
 DomCode KeycodeConverter::XkbKeycodeToDomCode(uint32_t xkb_keycode) {
   // Currently XKB keycode is the native keycode.
