--- gpxloggerd.c.orig	2020-03-05 17:50:39 UTC
+++ gpxloggerd.c
@@ -114,7 +114,9 @@ print_fix(struct gps_data_t *gpsdata)
 	    fix->latitude, fix->longitude);
 	if (!isnan(fix->altitude))
 		fprintf(logfile, "    <ele>%.f</ele>\n", fix->altitude);
-	fprintf(logfile, "    <time>%s</time>\n", unix_to_iso8601(fix->time,
+// See https://gitlab.com/gpsd/gpsd/-/blob/master/gps.h#L70
+// Replaced by now_to_iso8601
+	fprintf(logfile, "    <time>%s</time>\n", now_to_iso8601(
 	    tbuf, sizeof(tbuf)));
 	if (verbose) {
 		switch (fix->mode) {
@@ -171,6 +173,11 @@ opennewfile(char *template)
 	print_gpx_header();
 }
 
+static double timespec_to_double(struct timespec ts)
+{
+	return ((double)(ts.tv_sec) + ((double)(ts.tv_nsec) / 1e9));
+}
+
 static void
 process(struct gps_data_t *gpsdata)
 {
@@ -189,10 +196,10 @@ process(struct gps_data_t *gpsdata)
 		return;
 
 	move = 0; /* stupid old gcc */
-	t = (time_t )floor(fix->time);
-	ot = (time_t )floor(ofix.time);
+	t = (time_t )floor(timespec_to_double(fix->time));
+	ot = (time_t )floor(timespec_to_double(ofix.time));
 	if (minbearing)
-		pt = (time_t )floor(pfix.time);
+		pt = (time_t )floor(timespec_to_double(pfix.time));
 	else
 		pt = ot;
 
@@ -521,7 +528,7 @@ reopen:
 		if (FD_ISSET(signal_fd[0], &fds))
 			process_signal();
 		if (FD_ISSET(gpsdata.gps_fd, &fds)) {
-			n = gps_read(&gpsdata);
+			n = gps_read(&gpsdata, NULL, 0);
 			if (n < 0) {
 				syslog(LOG_ERR, "gps_read(): %m, reopening");
 				gps_close(&gpsdata);
