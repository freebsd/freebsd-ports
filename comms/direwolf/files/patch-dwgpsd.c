--- dwgpsd.c.orig	2020-03-05 16:59:08 UTC
+++ dwgpsd.c
@@ -57,7 +57,10 @@
 // Debian bug report:  direwolf (1.2-1) FTBFS with libgps22 as part of the gpsd transition (#803605):
 // dwgps.c claims to only support GPSD_API_MAJOR_VERSION 5, but also builds successfully with
 // GPSD_API_MAJOR_VERSION 6 provided by libgps22 when the attached patch is applied.
-#if GPSD_API_MAJOR_VERSION < 5 || GPSD_API_MAJOR_VERSION > 6
+
+// Also compatible with API 9 with conditional compilation later.
+
+#if GPSD_API_MAJOR_VERSION < 5 || GPSD_API_MAJOR_VERSION > 9
 #error libgps API version might be incompatible.
 #endif
 
@@ -257,7 +260,19 @@ static void * read_gpsd_thread (void *arg)
 	    /* Fall thru to read which should get error and bail out. */
 	  }
 
+// https://github.com/wb2osz/direwolf/issues/196
+// https://bugzilla.redhat.com/show_bug.cgi?id=1674812
+
+// gps_read has two new parameters in API version 7.
+// It looks like this could be used to obtain the JSON message from the daemon.
+// Specify NULL, instead of message buffer space, if this is not desired.
+// Why couldn't they add a new function instead of introducing incompatibility?
+
+#if GPSD_API_MAJOR_VERSION >= 7
+	  if (gps_read (&gpsdata, NULL, 0) == -1) {
+#else
 	  if (gps_read (&gpsdata) == -1) {
+#endif
 	    text_color_set(DW_COLOR_ERROR);
 
 	    dw_printf ("------------------------------------------\n");
