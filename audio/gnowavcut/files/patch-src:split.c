--- src/split.c~	Mon Aug 20 17:34:37 2001
+++ src/split.c	Wed Apr 24 09:59:58 2002
@@ -42,17 +42,17 @@
 static void split_dialog_clicked_cb(GtkWidget *widget, gint button_number, gpointer data);
 static void split_create_dialog(SplitDialog *sdialog);
 static void split_write(SplitDialog *sdialog);
-static void split_set_wave_header(WaveInfo *dest_info, WaveInfo *base_info, int data_size);
+static void split_set_wave_header(WaveInfo *dest_info, WaveInfo *base_info, guint32 data_size);
 static SplitStatus split_write_loop(SplitDialog *sdialog);
 static void split_update_progress_all(SplitDialog *sdialog, int file_num);
-static void split_update_progress_file(SplitDialog *sdialog, int start, int end, int cur);
+static void split_update_progress_file(SplitDialog *sdialog, guint32 start, guint32 end, guint32 cur);
 static SplitStatus split_write_wave(SplitDialog *sdialog, gchar *base_file_name, int old_fd, WaveInfo *wi, TimeData *time);
 static SplitStatus split_write_wave_with_filtering(SplitDialog *sdialog, gchar *base_file_name, int old_fd, WaveInfo *wi, TimeData *time_data);
 static void split_start(GnoWavCut *gnowavcut, gboolean use_filter);
-static void split_update_progress_file(SplitDialog *sdialog, int start, int end, int cur)
+static void split_update_progress_file(SplitDialog *sdialog, guint32 start, guint32 end, guint32 cur)
 {
 	gchar *label_text;
-	int total_size, now_size;
+	guint32 total_size, now_size;
 	gfloat total_mbyte, now_mbyte;
 	gfloat ratio;
 
@@ -105,7 +105,7 @@
 
 	g_free(file_text);
 }
-static void split_set_wave_header(WaveInfo *dest_info, WaveInfo *base_info, int data_size)
+static void split_set_wave_header(WaveInfo *dest_info, WaveInfo *base_info, guint32 data_size)
 {
 	strncpy(dest_info->id_riff, "RIFF", 4);
 
@@ -133,7 +133,7 @@
 	gchar *file_name;
 	int new_fd;
 	WORD buf[BUFFER];
-	int now_point, len;
+	guint32 now_point, len;
 
 	file_name = g_strdup_printf("%s.%s", base_file_name, WAVE_FILE_SUFFIX);
 	new_fd = open(file_name, O_WRONLY | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
@@ -189,7 +189,7 @@
 	gchar *file_name;
 	int new_fd;
 	WORD buf[BUFFER];
-	int now_point, len;
+	guint32 now_point, len;
 
 	int pipe_fd[2];
 	int pid;
@@ -277,7 +277,7 @@
 	int old_fd;
 	GSList *timelist, *cur;
 	WaveInfo wi;
-	int data_size;
+	guint32 data_size;
 	int file_num;
 	gchar *base_file_name;
 	TimeData *time_data;
@@ -430,7 +430,7 @@
 static gboolean split_create_list(GnoWavCut *gnowavcut, SplitDialog *sdialog)
 {
 	gchar *s_start, *s_end;
-	int start, end, i;
+	guint32 start, end, i;
 	TimeData *time_data;
 	GtkWidget *clist;
 
