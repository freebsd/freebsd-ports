--- ui/events/keycodes/dom/keycode_converter.h.orig	2024-02-21 00:21:15 UTC
+++ ui/events/keycodes/dom/keycode_converter.h
@@ -63,7 +63,7 @@ class KeycodeConverter {
   // Convert a DomCode into a native keycode.
   static int DomCodeToNativeKeycode(DomCode code);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FREEBSD)
   // Convert a XKB keycode into a DomCode.
   static DomCode XkbKeycodeToDomCode(uint32_t xkb_keycode);
 
