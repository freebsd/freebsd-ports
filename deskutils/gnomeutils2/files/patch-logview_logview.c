--- logview/logview.c.orig	Fri May  7 21:47:59 2004
+++ logview/logview.c	Wed Aug  4 18:40:24 2004
@@ -781,7 +781,7 @@
 
 	if ( ! found) {
 		g_snprintf (full_name, sizeof (full_name),
-			    "%s/share/gnome-system-log/gnome-system-log-regexp.db", LOGVIEWINSTALLPREFIX);
+			    "%s/gnome-system-log/gnome-system-log-regexp.db", DATADIR);
 		if (access (full_name, R_OK) == 0) {
 			found = TRUE;
 			g_free (cfg->regexp_db_path);
@@ -804,7 +804,7 @@
 
 	if ( ! found) {
 		g_snprintf (full_name, sizeof (full_name),
-			    "%s/share/gnome-system-log/gnome-system-log-descript.db", LOGVIEWINSTALLPREFIX);
+			    "%s/gnome-system-log/gnome-system-log-descript.db", DATADIR);
 		if (access (full_name, R_OK) == 0) {
 			found = TRUE;
 			g_free (cfg->descript_db_path);
@@ -838,7 +838,7 @@
 
 	if ( ! found) {
 		g_snprintf (full_name, sizeof (full_name),
-			    "%s/share/gnome-system-log/gnome-system-log-actions.db", LOGVIEWINSTALLPREFIX);
+			    "%s/gnome-system-log/gnome-system-log-actions.db", DATADIR);
 		if (access (full_name, R_OK) == 0) {
 			found = TRUE;
 			g_free (cfg->action_db_path);
@@ -922,6 +922,7 @@
             /* remove trailing newline */
             if (logfile[strlen(logfile)-1] == '\n')
                 logfile[strlen(logfile)-1] = '\0';
+	    if (strcmp (logfile, "/dev/console") == 0) continue;
             fprintf(stderr, "Found a logfile: (%s)\n", logfile);
             return logfile;
         }
