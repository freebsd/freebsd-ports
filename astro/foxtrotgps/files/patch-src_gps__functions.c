--- src/gps_functions.c.orig	2019-07-10 05:35:12 UTC
+++ src/gps_functions.c
@@ -729,6 +729,11 @@ cb_gpsd_io_error(GIOChannel *src, GIOCondition conditi
 }
 
 
+static double
+timespec_to_double(struct timespec ts)
+{
+	return ((double)(ts.tv_sec) + ((double)(ts.tv_nsec) / 1e9));
+}
 
 static gboolean
 cb_gpsd_data(GIOChannel *src, GIOCondition condition, gpointer data)
@@ -753,12 +758,16 @@ cb_gpsd_data(GIOChannel *src, GIOCondition condition, 
 	{
 		gpsdata->satellites_used = libgps_gpsdata.satellites_used;
 		gpsdata->hdop = libgps_gpsdata.dop.hdop;
-		gpsdata->fix.time = libgps_gpsdata.fix.time;
+		gpsdata->fix.time = timespec_to_double(libgps_gpsdata.fix.time);
 		if (isnan(gpsdata->fix.time))
 		{
 			gpsdata->fix.time = (time_t) 0;
 		}
+#if GPSD_API_MAJOR_VERSION >= 10
+		gpsdata->valid = (libgps_gpsdata.fix.status != STATUS_UNK);
+#else
 		gpsdata->valid = (libgps_gpsdata.status != STATUS_NO_FIX);
+#endif
 		if (gpsdata->valid)
 		{
 			gpsdata->seen_valid = TRUE;
