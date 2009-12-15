--- src/calibre/devices/libusb.c.orig	2009-12-13 17:36:03.000000000 -0800
+++ src/calibre/devices/libusb.c	2009-12-13 17:36:08.000000000 -0800
@@ -12,7 +12,7 @@
 
 #define PY_SSIZE_T_CLEAN
 #include <Python.h>
-#include <libusb-1.0/libusb.h>
+#include <libusb.h>
 
 libusb_context *ctxt = NULL;
 
