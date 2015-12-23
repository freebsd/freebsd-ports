--- src/readcalls.c.orig	2015-11-03 16:15:23 UTC
+++ src/readcalls.c
@@ -641,7 +641,7 @@ int synclog(char *synclogfile)
 
     showmsg("Merging logfiles...\n");
     sleep(1);
-    sprintf(wgetcmd, "cat log1 log2 | sort -g -k4,4 | uniq -w79 > %s",
+    sprintf(wgetcmd, "cat log1 log2 | sort -g -k4,4 | uniq  > %s",
 	    logfile);
     if (system(wgetcmd) == 0)
 	showmsg("Merging logs successfull\n");
