--- src/gps_functions.c.orig	2011-03-22 21:11:33.000000000 +0300
+++ src/gps_functions.c	2011-03-22 21:58:20.000000000 +0300
@@ -31,7 +31,8 @@
 
 
 static GIOChannel *gpsd_io_channel =NULL;
-static struct gps_data_t *libgps_gpsdata = NULL;
+static struct gps_data_t libgps_gpsdata;
+static int libgps_initialized = 0;
 
 static guint sid1,  sid3; 
 guint watchdog;
@@ -699,9 +700,7 @@
 	gpsdata = NULL;
 	g_source_remove(sid1); 
 	g_source_remove(sid3); 
-	gps_close(libgps_gpsdata);
-	libgps_gpsdata = NULL;
-	
+	gps_close(&libgps_gpsdata);
 	
 	return FALSE; 
 }
@@ -713,28 +712,28 @@
 {
 	int ret;
 
-        if (libgps_gpsdata == NULL)
+        if (libgps_initialized == 0)
             return FALSE;
 
-	ret = gps_poll(libgps_gpsdata);
-	if (ret == 0)
+	ret = gps_read(&libgps_gpsdata);
+	if (ret > 0)
 	{
-		gpsdata->satellites_used = libgps_gpsdata->satellites_used;
-		gpsdata->hdop = libgps_gpsdata->dop.hdop;
-		gpsdata->fix.time = libgps_gpsdata->fix.time;
+		gpsdata->satellites_used = libgps_gpsdata.satellites_used;
+		gpsdata->hdop = libgps_gpsdata.dop.hdop;
+		gpsdata->fix.time = libgps_gpsdata.fix.time;
 		if (isnan(gpsdata->fix.time))
 		{
 			gpsdata->fix.time = (time_t) 0;
 		}
-		gpsdata->valid = (libgps_gpsdata->status != STATUS_NO_FIX);
+		gpsdata->valid = (libgps_gpsdata.status != STATUS_NO_FIX);
 		if (gpsdata->valid)
 		{
 			gpsdata->seen_vaild = TRUE;
-			gpsdata->fix.latitude = libgps_gpsdata->fix.latitude;
-			gpsdata->fix.longitude = libgps_gpsdata->fix.longitude;
-			gpsdata->fix.speed = libgps_gpsdata->fix.speed;
-			gpsdata->fix.heading = libgps_gpsdata->fix.track;
-			gpsdata->fix.altitude = libgps_gpsdata->fix.altitude;
+			gpsdata->fix.latitude = libgps_gpsdata.fix.latitude;
+			gpsdata->fix.longitude = libgps_gpsdata.fix.longitude;
+			gpsdata->fix.speed = libgps_gpsdata.fix.speed;
+			gpsdata->fix.heading = libgps_gpsdata.fix.track;
+			gpsdata->fix.altitude = libgps_gpsdata.fix.altitude;
 		}
 		
 		g_source_remove(watchdog);
@@ -758,11 +757,11 @@
 void *
 get_gps_thread(void *ptr)
 {
-	libgps_gpsdata = gps_open(global_server, global_port);
-	if (libgps_gpsdata)
+	if (gps_open(global_server, global_port, &libgps_gpsdata) == 0)
 	{
 		fprintf(stderr, "connection to gpsd SUCCEEDED \n");
-		
+
+		libgps_initialized = 1;
 		global_reconnect_gpsd = FALSE;
 		
 		if(!gpsdata)
@@ -771,12 +770,12 @@
 		}
 		
 	
-		gps_stream(libgps_gpsdata, WATCH_ENABLE | POLL_NONBLOCK, NULL);
+		gps_stream(&libgps_gpsdata, WATCH_ENABLE, NULL);
 		
 		watchdog = g_timeout_add_seconds_full(G_PRIORITY_DEFAULT_IDLE,60,reset_gpsd_io,NULL,NULL);
 		
 		
-		gpsd_io_channel = g_io_channel_unix_new(libgps_gpsdata->gps_fd);
+		gpsd_io_channel = g_io_channel_unix_new(libgps_gpsdata.gps_fd);
 		g_io_channel_set_flags(gpsd_io_channel, G_IO_FLAG_NONBLOCK, NULL);
 		
 		
