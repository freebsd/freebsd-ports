--- src/main.c.orig	2006-09-30 03:13:00.000000000 -0500
+++ src/main.c	2008-01-18 15:01:59.000000000 -0600
@@ -359,7 +359,7 @@
     /* create the temporary file names */
     orig_umask = umask(S_IRWXG|S_IRWXO);
     pid = getpid();
-    sprintf(tempdirpv, "%s/cscope.%d", tmpdir, pid);
+    snprintf(tempdirpv, sizeof(tempdirpv), "%s/cscope.%d", tmpdir, pid);
     if(mkdir(tempdirpv,S_IRWXU)) {
 	fprintf(stderr, "\
 cscope: Could not create private temp dir %s\n",
@@ -368,8 +368,13 @@
     }
     umask(orig_umask);
 
-    sprintf(temp1, "%s/cscope.1", tempdirpv);
-    sprintf(temp2, "%s/cscope.2", tempdirpv);
+    if ((strlen(tempdirpv) + strlen("/cscope.X")) > PATHLEN) {
+ 	fprintf(stderr, "cscope: Could not create private temp files\n");
+        myexit(1);
+    }
+
+    snprintf(temp1, sizeof(temp1), "%s/cscope.1", tempdirpv);
+    snprintf(temp2, sizeof(temp2), "%s/cscope.2", tempdirpv);
 
     /* if running in the foreground */
     if (signal(SIGINT, SIG_IGN) != SIG_IGN) {
@@ -379,6 +384,7 @@
     }
     /* cleanup on the hangup signal */
     signal(SIGHUP, myexit);
+    signal(SIGTERM, myexit);
 
     /* if the database path is relative and it can't be created */
     if (reffile[0] != '/' && access(".", WRITE) != 0) {
