--- logview/logview.c.orig	Tue Nov 30 00:29:01 2004
+++ logview/logview.c	Tue Nov 30 00:30:44 2004
@@ -656,7 +656,7 @@
 
 	if ( ! found) {
 		g_snprintf (full_name, sizeof (full_name),
-			    "%s/share/gnome-system-log/gnome-system-log-regexp.db", LOGVIEWINSTALLPREFIX);
+			    "%s/gnome-system-log/gnome-system-log-regexp.db", LOGVIEWINSTALLPREFIX);
 		if (access (full_name, R_OK) == 0) {
 			found = TRUE;
 			g_free (cfg->regexp_db_path);
@@ -678,7 +678,7 @@
 
 	if ( ! found) {
 		g_snprintf (full_name, sizeof (full_name),
-			    "%s/share/gnome-system-log/gnome-system-log-descript.db", LOGVIEWINSTALLPREFIX);
+			    "%s/gnome-system-log/gnome-system-log-descript.db", LOGVIEWINSTALLPREFIX);
 		if (access (full_name, R_OK) == 0) {
 			found = TRUE;
 			g_free (cfg->descript_db_path);
@@ -709,7 +709,7 @@
 
 	if ( ! found) {
 		g_snprintf (full_name, sizeof (full_name),
-			    "%s/share/gnome-system-log/gnome-system-log-actions.db", LOGVIEWINSTALLPREFIX);
+			    "%s/gnome-system-log/gnome-system-log-actions.db", LOGVIEWINSTALLPREFIX);
 		if (access (full_name, R_OK) == 0) {
 			found = TRUE;
 			g_free (cfg->action_db_path);
