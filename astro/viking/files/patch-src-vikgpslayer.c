--- src/vikgpslayer.c.orig	2011-03-22 22:23:24.000000000 +0300
+++ src/vikgpslayer.c	2011-03-22 22:45:18.000000000 +0300
@@ -1308,7 +1308,7 @@
 
 }
 
-static void gpsd_raw_hook(VglGpsd *vgpsd, gchar *data)
+static void gpsd_raw_hook(VglGpsd *vgpsd)
 {
   gboolean update_all = FALSE;
   VikGpsLayer *vgl = vgpsd->vgl;
@@ -1376,10 +1376,14 @@
 static gboolean gpsd_data_available(GIOChannel *source, GIOCondition condition, gpointer data)
 {
   VikGpsLayer *vgl = data;
+  int nread;
+
   if (condition == G_IO_IN) {
-    if (!gps_poll(&vgl->vgpsd->gpsd))
+    if ((nread = gps_read(&vgl->vgpsd->gpsd)) >= 0) {
+      if (nread)
+	gpsd_raw_hook(vgl->vgpsd);
       return TRUE;
-    else {
+    } else {
       g_warning("Disconnected from gpsd. Trying to reconnect");
       rt_gpsd_disconnect(vgl);
       rt_gpsd_connect(vgl, FALSE);
@@ -1407,23 +1411,15 @@
 static gboolean rt_gpsd_try_connect(gpointer *data)
 {
   VikGpsLayer *vgl = (VikGpsLayer *)data;
-#ifndef HAVE_GPS_OPEN_R
-  struct gps_data_t *gpsd = gps_open(vgl->gpsd_host, vgl->gpsd_port);
 
-  if (gpsd == NULL) {
-#else
   vgl->vgpsd = g_malloc(sizeof(VglGpsd));
 
-  if (gps_open_r(vgl->gpsd_host, vgl->gpsd_port, /*(struct gps_data_t *)*/vgl->vgpsd) != 0) {
-#endif
+  if (gps_open(vgl->gpsd_host, vgl->gpsd_port, (struct gps_data_t *)vgl->vgpsd) != 0) {
     g_warning("Failed to connect to gpsd at %s (port %s). Will retry in %d seconds",
                      vgl->gpsd_host, vgl->gpsd_port, vgl->gpsd_retry_interval);
     return TRUE;   /* keep timer running */
   }
 
-#ifndef HAVE_GPS_OPEN_R
-  vgl->vgpsd = realloc(gpsd, sizeof(VglGpsd));
-#endif
   vgl->vgpsd->vgl = vgl;
 
   vgl->realtime_fix.dirty = vgl->last_fix.dirty = FALSE;
@@ -1439,15 +1435,10 @@
     vik_trw_layer_add_track(vtl, vgl->realtime_track_name, vgl->realtime_track);
   }
 
-  gps_set_raw_hook(&vgl->vgpsd->gpsd, gpsd_raw_hook);
   vgl->realtime_io_channel = g_io_channel_unix_new(vgl->vgpsd->gpsd.gps_fd);
   vgl->realtime_io_watch_id = g_io_add_watch( vgl->realtime_io_channel,
                     G_IO_IN | G_IO_ERR | G_IO_HUP, gpsd_data_available, vgl);
-#if HAVE_GPS_STREAM
   gps_stream(&vgl->vgpsd->gpsd, WATCH_ENABLE, NULL);
-#else
-  gps_query(&vgl->vgpsd->gpsd, "w+x");
-#endif
   return FALSE;  /* no longer called by timeout */
 }
 
@@ -1501,11 +1492,7 @@
   }
   if (vgl->vgpsd) {
     gps_close(&vgl->vgpsd->gpsd);
-#ifdef HAVE_GPS_OPEN_R
     g_free(vgl->vgpsd);
-#else
-    free(vgl->vgpsd);
-#endif
     vgl->vgpsd = NULL;
   }
 
