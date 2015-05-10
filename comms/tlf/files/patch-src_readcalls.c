--- src/readcalls.c.orig	2014-05-15 21:02:23 UTC
+++ src/readcalls.c
@@ -492,7 +492,7 @@ int synclog(char *synclogfile)
 
     showmsg("Merging logfiles...\n");
     sleep(1);
-    sprintf(wgetcmd, "cat log1 log2 | sort -g -k4,4 | uniq -w79 > %s",
+    sprintf(wgetcmd, "cat log1 log2 | sort -g -k4,4 | uniq  > %s",
 	    logfile);
     if (system(wgetcmd) == 0)
 	showmsg("Merging logs successfull\n");
