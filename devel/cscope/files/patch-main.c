--- src/main.c.orig	Sat Sep 30 01:13:00 2006
+++ src/main.c	Thu Oct  5 15:21:30 2006
@@ -359,7 +359,7 @@ cscope: TMPDIR to a valid directory\n");
     /* create the temporary file names */
     orig_umask = umask(S_IRWXG|S_IRWXO);
     pid = getpid();
-    sprintf(tempdirpv, "%s/cscope.%d", tmpdir, pid);
+    snprintf(tempdirpv, sizeof(tempdirpv), "%s/cscope.%d", tmpdir, pid);
     if(mkdir(tempdirpv,S_IRWXU)) {
 	fprintf(stderr, "\
 cscope: Could not create private temp dir %s\n",
@@ -368,8 +368,13 @@ cscope: Could not create private temp di
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
