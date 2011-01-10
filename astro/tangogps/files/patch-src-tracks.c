--- src/tracks.c	Sat Jul 10 06:54:31 2010 -0700
+++ src/tracks.c	Fri Jul 23 06:17:08 2010 -0700
@@ -218,7 +218,6 @@
 	gchar data[256];
 	time_t time_sec;
 	struct tm *ts;
-	int heartfreq = 42;
 	
 	
 	if(gpsdata->valid)
@@ -228,17 +227,15 @@
 		ts = localtime(&time_sec);
 		strftime(buffer, sizeof(buffer), "%Y-%m-%dT%H:%M:%SZ", ts);
 		
-		heartfreq = (hrmdata) ? hrmdata->freq : 0;
 		
-		snprintf(data, sizeof(data), "%f,%f,%.1f,%.1f,%.1f,%.1f,%s,%d\n",
+		snprintf(data, sizeof(data), "%f,%f,%.1f,%.1f,%.1f,%.1f,%s\n",
 				gpsdata->fix.latitude,
 				gpsdata->fix.longitude,
 				gpsdata->fix.altitude,
 				gpsdata->fix.speed,
 				gpsdata->fix.heading,
 				gpsdata->hdop,
-				buffer,
-				heartfreq);
+				buffer);
 		
 		if (fp) fprintf(fp, "%s", data);
 	}
@@ -521,8 +518,6 @@
 		tp->hdop	 = atof(arr[5]);
 		tp->time_iso8106 = g_strchomp(arr[6]);
 		
-		if(arr[7] != NULL)
-			tp->heart = atoi(arr[7]);
 				
 		list = g_slist_prepend(list, tp);
 	}
