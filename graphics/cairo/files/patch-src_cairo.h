--- src/cairo.h.orig	2010-10-29 16:27:48.000000000 +0200
+++ src/cairo.h	2010-10-29 16:28:07.000000000 +0200
@@ -1973,7 +1973,7 @@ typedef enum _cairo_device_type {
     CAIRO_DEVICE_TYPE_SCRIPT,
     CAIRO_DEVICE_TYPE_XCB,
     CAIRO_DEVICE_TYPE_XLIB,
-    CAIRO_DEVICE_TYPE_XML,
+    CAIRO_DEVICE_TYPE_XML
 } cairo_device_type_t;
 
 cairo_public cairo_device_type_t
