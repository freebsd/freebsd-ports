--- src/utils.c~	Mon Aug 20 17:22:14 2001
+++ src/utils.c	Tue Apr 23 21:36:11 2002
@@ -41,7 +41,7 @@
 	gtk_widget_show(gnome_message_box_new(msg, GNOME_MESSAGE_BOX_WARNING, GNOME_STOCK_BUTTON_OK,
 					      NULL));
 }
-gchar *utils_get_time_from_seconds(int in_sec)
+gchar *utils_get_time_from_seconds(guint32 in_sec)
 {
 	int sec;
 	int min;
@@ -54,12 +54,12 @@
 
 	return time;
 }
-gchar *utils_get_mini_time_from_cur(WaveInfo *wave_info, int cur)
+gchar *utils_get_mini_time_from_cur(WaveInfo *wave_info, guint32 cur)
 {
-	int i, j;
-	int micro;
-	int sec;
-	int min;
+	guint32 i, j;
+	guint32 micro;
+	guint32 sec;
+	guint32 min;
 	gchar *time;
 
 	i = (cur - WAVE_HEADER_SIZE) / wave_info->size_per_sec;
@@ -75,16 +75,16 @@
 	return time;
 }
 
-gboolean utils_get_cur_from_mini_time(WaveInfo *wave_info, gchar *time_in, int *cur_out)
+gboolean utils_get_cur_from_mini_time(WaveInfo *wave_info, gchar *time_in, guint32 *cur_out)
 {
-	int cur;
+	guint32 cur;
 	gchar *s_sec;
 	gchar *s_msec;
 	gchar *endptr;
 	gchar *time;
-	long l_min;
-	long l_sec;
-	long l_msec;
+	guint32 l_min;
+	guint32 l_sec;
+	guint32 l_msec;
 
 	if(cur_out != NULL)
 		*cur_out = 0;
@@ -99,7 +99,8 @@
 		g_free(time);
 		return FALSE;
 	}
-	if(l_min > INT_MAX / 61 / wave_info->size_per_sec || l_min < 0) {
+	/* Should be G_UINT32MAX (or similar), but glib doesn't provide that. */
+	if(l_min > UINT_MAX / 61 / wave_info->size_per_sec || l_min < 0) {
 		g_warning(_("get_cur_from_mini_time error, min is too large or too small.\n"));
 		g_free(time);
 		return FALSE;
