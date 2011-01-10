--- src/globals.h	Sat Jul 10 06:54:31 2010 -0700
+++ src/globals.h	Fri Jul 23 06:17:01 2010 -0700
@@ -91,11 +91,6 @@
 	gboolean seen_vaild; /* ever had a vaild fix? */
 } gps_data_t;
 
-typedef struct {
-	int freq;
-	int min;
-	int max;
-} hrm_data_t;
 
 extern GdkPixmap 	*pixmap;
 extern GtkWidget	*window1, *window2;
@@ -126,7 +121,6 @@
 
 
 extern gps_data_t *gpsdata;
-extern hrm_data_t *hrmdata;
 
 extern GQueue		*trackpoint_list;
 extern GSList		*friends_list;
@@ -141,7 +135,6 @@
 extern trackpoint_t	global_myposition;
 extern gboolean		trip_logger_on;
 extern gboolean		trip_livelog_on;
-extern gboolean		hrm_on;
 
 extern gchar		*global_curr_reponame;
 extern int		global_repo_cnt;
@@ -156,7 +149,6 @@
 extern gboolean		global_mapmode;
 extern gboolean		global_autocenter;
 extern gboolean		global_reconnect_gpsd;
-extern gboolean		global_reconnect_hrm;
 extern int		global_tiles_in_dl_queue;
 
 extern gboolean		global_show_pois;
@@ -179,7 +171,6 @@
 extern gchar		*global_server;
 extern gchar		*global_port;
 
-extern gchar		*global_hrm_bt_addr;
 
 extern gchar		*global_home_dir;
 extern gchar		*tangogps_dir;
