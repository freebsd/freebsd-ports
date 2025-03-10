--- src/usb/usb_string.h.orig	2013-01-07 10:35:29 UTC
+++ src/usb/usb_string.h
@@ -25,7 +25,7 @@ namespace usb {
 namespace librevisa {
 namespace usb {
 
-typedef std::basic_string<uint16_t> usb_string;
+typedef std::basic_string<char16_t> usb_string;
 
 }
 }
