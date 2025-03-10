--- fobos/fobos.c.orig	2024-11-04 01:02:42 UTC
+++ fobos/fobos.c
@@ -26,7 +26,7 @@
 #pragma comment(lib, "libusb-1.0.lib")                                             
 #define printf_internal _cprintf
 #else
-#include <libusb-1.0/libusb.h>
+#include <libusb.h>
 #include <unistd.h>
 #endif
 #ifndef printf_internal
