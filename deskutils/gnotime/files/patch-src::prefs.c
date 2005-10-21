--- src/prefs.c.orig	Fri Sep  2 23:08:26 2005
+++ src/prefs.c	Fri Oct 21 11:54:01 2005
@@ -199,10 +199,12 @@
 scan_time_string (const char *str)
 {
 	int hours=0, minutes=0, seconds = 0;
+	int totalsecs;
 	char buff[24];
+	char *p;
 	strncpy (buff, str, 24);
 	buff[23]=0;
-	char * p = strchr (buff, ':');
+	p = strchr (buff, ':');
 	if (p) *p = 0;
 	hours = atoi (buff);
 	if (p)
@@ -220,7 +222,7 @@
 	minutes %= 60;
 	hours %= 24;
 
-	int totalsecs = hours*3600 + minutes*60 + seconds;
+	totalsecs = hours*3600 + minutes*60 + seconds;
 	if (12*3600 < totalsecs) totalsecs -= 24*3600;
 	return totalsecs;
 }
@@ -391,15 +393,17 @@
 	if (5 == page)
 	{
 		int change = 0;
+		const char *buff;
+		int off, day;
 		config_idle_timeout = atoi(gtk_entry_get_text(GTK_ENTRY(odlg->idle_secs)));
 		config_no_project_timeout = atoi(gtk_entry_get_text(GTK_ENTRY(odlg->no_project_secs)));
 
 		/* Hunt for the hour-of night on which to start */
-		const char * buff = gtk_entry_get_text (odlg->daystart_secs);
-		int off = scan_time_string (buff);
+		buff = gtk_entry_get_text (odlg->daystart_secs);
+		off = scan_time_string (buff);
 		SET_VAL (config_daystart_offset,off);
 
-		int day = get_optionmenu_item (odlg->weekstart_menu);
+		day = get_optionmenu_item (odlg->weekstart_menu);
 		SET_VAL (config_weekstart_offset, day);
 
 		if (change)
@@ -440,6 +444,8 @@
 options_dialog_set(PrefsDialog *odlg)
 {
 	char s[30];
+	int hour, secs, day;
+	char buff[24];
 
 	SET_ACTIVE(secs);
 	SET_ACTIVE(statusbar);
@@ -518,7 +524,6 @@
 	gtk_entry_set_text(GTK_ENTRY(odlg->no_project_secs), s);
 
 	/* Set the correct menu item based on current values */
-	int hour;
 	if (0<config_daystart_offset)
 	{
 		hour = (config_daystart_offset +1800)/3600;
@@ -533,14 +538,13 @@
 	set_optionmenu_item (odlg->daystart_menu, hour);
 
 	/* Print the daystart offset as a string in 24 hour time */
-	int secs = config_daystart_offset;
+	secs = config_daystart_offset;
 	if (0 > secs) secs += 24*3600;
-	char buff[24];
 	qof_print_hours_elapsed_buff (buff, 24, secs, config_show_secs);   
 	gtk_entry_set_text (odlg->daystart_secs, buff);
 
 	/* Set the correct menu item based on current values */
-	int day = config_weekstart_offset;
+	day = config_weekstart_offset;
 	set_optionmenu_item (odlg->weekstart_menu, day);
 
 	/* set to unmodified as it reflects the current state of the app */
@@ -554,12 +558,13 @@
 {
 	PrefsDialog *dlg = data;
 
+	int secs;
+	char buff[24];
 	int hour = get_optionmenu_item (dlg->daystart_menu);
 	hour += -3;  /* menu starts at 9PM */
 
-	int secs = hour * 3600;
+	secs = hour * 3600;
 	if (0 > secs) secs += 24*3600;
-	char buff[24];
 	qof_print_hours_elapsed_buff (buff, 24, secs, config_show_secs);   
 	gtk_entry_set_text (dlg->daystart_secs, buff);
 }
