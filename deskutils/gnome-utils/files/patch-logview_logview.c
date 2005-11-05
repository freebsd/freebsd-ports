--- logview/logview.c.orig	Tue Oct  4 12:31:47 2005
+++ logview/logview.c	Tue Oct  4 12:32:04 2005
@@ -930,7 +930,7 @@
 
 	if ( ! found) {
 		g_snprintf (full_name, sizeof (full_name),
-			    "%s/share/gnome-system-log/gnome-system-log-regexp.db", LOGVIEWINSTALLPREFIX);
+			    "%s/gnome-system-log/gnome-system-log-regexp.db", LOGVIEWINSTALLPREFIX);
 		if (access (full_name, R_OK) == 0) {
 			found = TRUE;
 			g_free (cfg->regexp_db_path);
@@ -952,7 +952,7 @@
 
 	if ( ! found) {
 		g_snprintf (full_name, sizeof (full_name),
-			    "%s/share/gnome-system-log/gnome-system-log-descript.db", LOGVIEWINSTALLPREFIX);
+			    "%s/gnome-system-log/gnome-system-log-descript.db", LOGVIEWINSTALLPREFIX);
 		if (access (full_name, R_OK) == 0) {
 			found = TRUE;
 			g_free (cfg->descript_db_path);
@@ -983,7 +983,7 @@
 
 	if ( ! found) {
 		g_snprintf (full_name, sizeof (full_name),
-			    "%s/share/gnome-system-log/gnome-system-log-actions.db", LOGVIEWINSTALLPREFIX);
+			    "%s/gnome-system-log/gnome-system-log-actions.db", LOGVIEWINSTALLPREFIX);
 		if (access (full_name, R_OK) == 0) {
 			found = TRUE;
 			g_free (cfg->action_db_path);
