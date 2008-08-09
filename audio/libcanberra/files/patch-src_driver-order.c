--- src/driver-order.c.orig	2008-08-09 16:04:21.964956000 -0400
+++ src/driver-order.c	2008-08-09 16:04:21.964956000 -0400
@@ -34,6 +34,9 @@ const char* const ca_driver_order[] = {
 #ifdef HAVE_ALSA
     "alsa",
 #endif
+#ifdef HAVE_OSS
+    "oss",
+#endif
     /* ... */
     NULL
 };
