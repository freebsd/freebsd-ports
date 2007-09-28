--- src/readcalls.c.orig	Wed Apr  5 03:16:50 2006
+++ src/readcalls.c	Thu Sep 27 19:54:14 2007
@@ -563,7 +563,7 @@
 
 	showmsg ("Merging logfiles...\n");
 	sleep(1);
-	sprintf(wgetcmd, "cat log1 log2 | sort -g -k4,4 | uniq -w79 > %s", logfile);
+	sprintf(wgetcmd, "cat log1 log2 | sort -g -k4,4 | uniq > %s", logfile);
 	if (system(wgetcmd) == 0)
 		showmsg ("Merging logs successfull\n");
 	else
