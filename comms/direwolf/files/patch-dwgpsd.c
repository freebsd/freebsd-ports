--- dwgpsd.c.orig	2017-01-20 00:11:50 UTC
+++ dwgpsd.c
@@ -77,8 +77,9 @@ static void * read_gpsd_thread (void *ar
  * Information for interface to gpsd daemon. 
  */
 
+#if ENABLE_GPSD
 static struct gps_data_t gpsdata;
-
+#endif
 
 /*-------------------------------------------------------------------
  *
