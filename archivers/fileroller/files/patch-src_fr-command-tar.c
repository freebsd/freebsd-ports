--- src/fr-command-tar.c.orig	Mon Mar  8 18:20:07 2004
+++ src/fr-command-tar.c	Sun Mar 14 00:14:41 2004
@@ -196,6 +196,11 @@
 	return g_strndup (f_start + 1, f_end - f_start);
 }
 
+static char *months[] = {
+	"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct",
+	"Nov", "Dec"
+};
+
 
 static void
 process_line (char     *line, 
@@ -204,28 +209,36 @@
 	FileData    *fdata;
 	FRCommand   *comm = FR_COMMAND (data);
 	char       **fields;
-	int          date_idx;
-	char        *field_date, *field_time, *field_size, *field_name;
+	int          i;
+	struct tm    tm = {0, };
+	char       **time_fields;
+	const char  *field_name;
 
 	g_return_if_fail (line != NULL);
 
 	fdata = file_data_new ();
 
-	date_idx = get_index_from_pattern (line, "%n%n%n%n-%n%n-%n%n %n%n:%n%n");
+	fields = split_line (line, 7);
 
-	field_size = get_prev_field (line, date_idx, 1);
-	fdata->size = atol (field_size);
-	g_free (field_size);
-
-	field_date = get_next_field (line, date_idx, 1);
-	field_time = get_next_field (line, date_idx, 2);
-	fdata->modified = mktime_from_string (field_date, field_time);
-	g_free (field_date);
-	g_free (field_time);
+	fdata->size = atol (fields[2]);
+	for (i = 0; i < 12; i++) {
+		if (!strncmp(fields[3], months[i], 3)) break;
+	}
+	tm.tm_mon = i;
+	tm.tm_year = atoi (fields[6]) - 1900;
+	tm.tm_mday = atoi (fields[4]);
+	time_fields = g_strsplit(fields[5], ":", 2);
+	tm.tm_hour = atoi (time_fields[0]);
+	tm.tm_min = atoi (time_fields[1]);
+	tm.tm_sec = 0;
+	tm.tm_isdst = -1;
+	fdata->modified = mktime(&tm);
+	g_strfreev (fields);
+	g_strfreev (time_fields);
 
 	/* Full path */
 
-	field_name = get_next_field (line, date_idx, 3);
+	field_name = get_last_field (line, 8);
 	fields = g_strsplit (field_name, " -> ", 2);
 
 	if (fields[1] == NULL) {
@@ -244,7 +257,6 @@
 	if (fields[1] != NULL)
 		fdata->link = g_strdup (fields[1]);
 	g_strfreev (fields);
-	g_free (field_name);
 
 	fdata->name = g_strdup (file_name_from_path (fdata->full_path));
 	fdata->path = remove_level_from_path (fdata->full_path);
