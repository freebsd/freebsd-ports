--- src/fr-command-tar.c.orig	Mon May 19 14:15:50 2003
+++ src/fr-command-tar.c	Tue May 20 20:43:39 2003
@@ -83,6 +83,11 @@
 	return mktime (&tm);
 }
 
+static char *months[] = {
+    "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct",
+    "Nov", "Dec"
+};
+
 
 static void
 process_line (char     *line, 
@@ -92,19 +97,34 @@
 	FRCommand   *comm = FR_COMMAND (data);
 	char       **fields;
 	const char  *name_field;
+	int          i;
+	struct tm    tm = {0, };
+	char       **time_fields;
 
 	g_return_if_fail (line != NULL);
 
 	fdata = file_data_new ();
 
-	fields = split_line (line, 5);
+	fields = split_line (line, 7);
 	fdata->size = atol (fields[2]);
-	fdata->modified = mktime_from_string (fields[3], fields[4]);
+	for (i = 0; i < 12; i++) {
+	    if (!strncmp(fields[3], months[i], 3)) break;
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
 	g_strfreev (fields);
+	g_strfreev (time_fields);
 
 	/* Full path */
 
-	name_field = get_last_field (line, 6);
+	name_field = get_last_field (line, 8);
 	fields = g_strsplit (name_field, " -> ", 2);
 
 	if (fields[1] == NULL) {
