--- repmgr.c.orig	2014-03-17 21:27:40.000000000 +0800
+++ repmgr.c	2014-05-24 17:55:10.996404127 +0800
@@ -1871,7 +1871,7 @@
 	char host_string[MAXLEN];
 	int	 r;
 
-	if (strnlen(options.rsync_options, MAXLEN) == 0)
+	if (strlen(options.rsync_options) == 0)
 		maxlen_snprintf(
 		    rsync_flags, "%s",
 		    "--archive --checksum --compress --progress --rsh=ssh");
