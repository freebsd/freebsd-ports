--- src/globals.c	Sat Jul 10 06:54:31 2010 -0700
+++ src/globals.c	Fri Jul 23 06:17:00 2010 -0700
@@ -37,7 +37,6 @@
 
 
 gps_data_t *gpsdata = NULL;
-hrm_data_t *hrmdata = NULL;
 
 GQueue		*trackpoint_list= NULL;
 GSList		*friends_list	= NULL;
@@ -53,7 +52,6 @@
 gboolean	trip_counter_on	= TRUE;
 gboolean	trip_logger_on	= FALSE;
 gboolean	trip_livelog_on	= FALSE;
-gboolean	hrm_on		= FALSE;
 
 trackpoint_t	global_myposition;
 
@@ -72,7 +70,6 @@
 gboolean	global_mapmode = TRUE;
 gboolean	global_autocenter = TRUE;
 gboolean	global_reconnect_gpsd = TRUE;
-gboolean	global_reconnect_hrm = TRUE;
 int		global_tiles_in_dl_queue = 0;
 
 gboolean	global_show_friends = FALSE;
@@ -95,7 +92,6 @@
 gchar		*global_server	= NULL;
 gchar		*global_port	= NULL;
 
-gchar		*global_hrm_bt_addr = NULL;
 
 gchar		*global_home_dir = NULL;
 gchar		*tangogps_dir = NULL;
