--- libgps_json.c.orig
+++ libgps_json.c
@@ -203,7 +203,7 @@ static int json_sky_read(const char *buf, struct gps_data_t *gpsdata,
 	                             .len = sizeof(gpsdata->tag)},
 	{"time",       t_string,  .addr.string = tbuf,
 			             .len = sizeof(tbuf)},
-	{"time",       t_real,    .addr.real = &gpsdata->fix.time,
+	{"time",       t_real,    .addr.real = &gpsdata->skyview_time,
 	      	                     .dflt.real = NAN},
 	{"hdop",       t_real,    .addr.real    = &gpsdata->dop.hdop,
 	                             .dflt.real = NAN},
