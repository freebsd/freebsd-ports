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
@@ -744,7 +749,7 @@ cb_gpsd_data(GIOChannel *src, GIOCondition condition, 
         if (!libgps_initialized)
             return FALSE;
 
-	ret = gps_read(&libgps_gpsdata);
+	ret = gps_read(&libgps_gpsdata, NULL, 0);
         /* Note that gps_read() will never actually return 0
            (zero-length reads are converted internally to a -1 return,
             since they mean that the connection to the daemon has closed),
@@ -755,7 +760,7 @@ cb_gpsd_data(GIOChannel *src, GIOCondition condition, 
 	{
 		gpsdata->satellites_used = libgps_gpsdata.satellites_used;
 		gpsdata->hdop = libgps_gpsdata.dop.hdop;
-		gpsdata->fix.time = libgps_gpsdata.fix.time;
+		gpsdata->fix.time = timespec_to_double(libgps_gpsdata.fix.time);
 		if (isnan(gpsdata->fix.time))
 		{
 			gpsdata->fix.time = (time_t) 0;
