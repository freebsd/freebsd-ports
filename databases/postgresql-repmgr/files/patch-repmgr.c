--- ./repmgr.c.orig	2012-07-28 02:30:35.000000000 +1000
+++ ./repmgr.c	2012-12-04 19:41:06.157429458 +1100
@@ -28,6 +28,7 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <sys/wait.h>
 #include <time.h>
 #include <unistd.h>
 
@@ -1603,11 +1604,18 @@
 	char script[MAXLEN];
 	int	 r;
 
+/* On some OS, true is located in a different place than in Linux */
+#ifdef __FreeBSD__
+#define TRUEBIN_PATH "/usr/bin/true"
+#else
+#define TRUEBIN_PATH "/bin/true"
+#endif
+
 	/* Check if we have ssh connectivity to host before trying to rsync */
 	if (!remote_user[0])
-		maxlen_snprintf(script, "ssh -o Batchmode=yes %s /bin/true", host);
+		maxlen_snprintf(script, "ssh -o Batchmode=yes %s %s", host, TRUEBIN_PATH);
 	else
-		maxlen_snprintf(script, "ssh -o Batchmode=yes %s -l %s /bin/true", host, remote_user);
+		maxlen_snprintf(script, "ssh -o Batchmode=yes %s -l %s %s", host, remote_user, TRUEBIN_PATH);
 
 	log_debug(_("command is: %s"), script);
 	r = system(script);
@@ -1625,7 +1633,7 @@
 	char host_string[MAXLEN];
 	int	 r;
 
-	if (strnlen(options.rsync_options, MAXLEN) == 0)
+	if (strlen(options.rsync_options) == 0)
 		maxlen_snprintf(
 		    rsync_flags, "%s",
 		    "--archive --checksum --compress --progress --rsh=ssh");
