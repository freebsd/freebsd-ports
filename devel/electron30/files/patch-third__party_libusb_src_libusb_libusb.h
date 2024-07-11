--- third_party/libusb/src/libusb/libusb.h.orig	2024-04-15 20:34:25 UTC
+++ third_party/libusb/src/libusb/libusb.h
@@ -60,7 +60,7 @@ typedef unsigned __int32  uint32_t;
 #include <sys/types.h>
 #endif
 
-#if defined(__linux) || defined(__APPLE__) || defined(__CYGWIN__)
+#if defined(__linux) || defined(__APPLE__) || defined(__CYGWIN__) || defined(__OpenBSD__) || defined(__FreeBSD__)
 #include <sys/time.h>
 #endif
 
