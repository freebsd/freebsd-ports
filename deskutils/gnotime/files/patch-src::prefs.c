--- src/prefs.c.orig	Mon May 24 20:25:52 2004
+++ src/prefs.c	Mon May 24 20:29:36 2004
@@ -200,10 +200,12 @@
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
@@ -221,7 +223,7 @@
 	minutes %= 60;
 	hours %= 24;
 
-	int totalsecs = hours*3600 + minutes*60 + seconds;
+	totalsecs = hours*3600 + minutes*60 + seconds;
 	if (12*3600 < totalsecs) totalsecs -= 24*3600;
 	return totalsecs;
 }
@@ -373,14 +375,16 @@
 	if (5 == page)
 	{
 		int change = 0;
+		int off, day;
+		const char *buff;
 		config_idle_timeout = atoi(gtk_entry_get_text(GTK_ENTRY(odlg->idle_secs)));
 
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
@@ -421,6 +425,8 @@
 options_dialog_set(PrefsDialog *odlg)
 {
 	char s[30];
+	int hour, secs, day;
+	char buff[24];
 
 	SET_ACTIVE(secs);
 	SET_ACTIVE(statusbar);
@@ -495,7 +501,6 @@
 	gtk_entry_set_text(GTK_ENTRY(odlg->idle_secs), s);
 
 	/* Set the correct menu item based on current values */
-	int hour;
 	if (0<config_daystart_offset)
 	{
 		hour = (config_daystart_offset +1800)/3600;
@@ -510,14 +515,13 @@
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
@@ -531,12 +535,13 @@
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
