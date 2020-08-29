--- src/gps_functions.c.orig	2020-03-05 17:21:38 UTC
+++ src/gps_functions.c
@@ -735,6 +735,11 @@ cb_gpsd_io_error(GIOChannel *src, GIOCondition conditi
 }
 
 
+static double
+timespec_to_double(struct timespec ts)
+{
+	return ((double)(ts.tv_sec) + ((double)(ts.tv_nsec) / 1e9));
+}
 
 static gboolean
 cb_gpsd_data(GIOChannel *src, GIOCondition condition, gpointer data)
@@ -755,7 +760,7 @@ cb_gpsd_data(GIOChannel *src, GIOCondition condition, 
 	{
 		gpsdata->satellites_used = libgps_gpsdata.satellites_used;
 		gpsdata->hdop = libgps_gpsdata.dop.hdop;
-		gpsdata->fix.time = libgps_gpsdata.fix.time;
+		gpsdata->fix.time = timespec_to_double(libgps_gpsdata.fix.time);
 		if (isnan(gpsdata->fix.time))
 		{
 			gpsdata->fix.time = (time_t) 0;
