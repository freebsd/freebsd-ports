--- logview/userprefs.c.orig	Tue Nov 30 00:35:05 2004
+++ logview/userprefs.c	Tue Nov 30 00:36:34 2004
@@ -56,6 +56,7 @@
 			/* remove trailing newline */
 			if (logfile[strlen(logfile)-1] == '\n')
 				logfile[strlen(logfile)-1] = '\0';
+			if (strcmp (logfile, "/dev/console") == 0) continue;
 			return logfile;
 		}
 	}
