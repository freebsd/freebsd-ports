--- logview/logview.c.orig	Tue May  7 00:03:16 2002
+++ logview/logview.c	Tue May  7 00:04:37 2002
@@ -903,7 +903,7 @@
 
 	if ( ! found) {
 		g_snprintf (full_name, sizeof (full_name),
-			    "%s/share/gnome-system-log/gnome-system-log-regexp.db", LOGVIEWINSTALLPREFIX);
+			    "%s/gnome-system-log/gnome-system-log-regexp.db", DATADIR);
 		if (access (full_name, R_OK) == 0) {
 			found = TRUE;
 			g_free (cfg->regexp_db_path);
@@ -926,7 +926,7 @@
 
 	if ( ! found) {
 		g_snprintf (full_name, sizeof (full_name),
-			    "%s/share/gnome-system-log/gnome-system-log-descript.db", LOGVIEWINSTALLPREFIX);
+			    "%s/gnome-system-log/gnome-system-log-descript.db", DATADIR);
 		if (access (full_name, R_OK) == 0) {
 			found = TRUE;
 			g_free (cfg->descript_db_path);
@@ -960,7 +960,7 @@
 
 	if ( ! found) {
 		g_snprintf (full_name, sizeof (full_name),
-			    "%s/share/gnome-system-log/gnome-system-log-actions.db", LOGVIEWINSTALLPREFIX);
+			    "%s/gnome-system-log/gnome-system-log-actions.db", DATADIR);
 		if (access (full_name, R_OK) == 0) {
 			found = TRUE;
 			g_free (cfg->action_db_path);
