--- tools/duende.c.orig	Sat Jun  2 13:40:35 2007
+++ tools/duende.c	Sat Jun  2 13:41:01 2007
@@ -35,10 +35,13 @@
 #include <signal.h>
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 #include <syslog.h>
+#include <sys/param.h>
 #include <sys/time.h>
 #include <sys/types.h>
 #include <sys/wait.h>
+#include <libutil.h>
 #include <unistd.h>
 #include "../MaraDns.h"
 
@@ -139,6 +142,9 @@
     int exit_status;
     pid_t pid, log_pid;
     int stream1[2]; /* Used for piping */
+    struct pidfh *pfh;
+    char *name;
+    char *pidfile;
     if(argv[0] == NULL || argv[1] == NULL) {
         printf("Usage: duende [program] [arguments]\n");
 	exit(1);
@@ -202,7 +208,24 @@
 	    log_helper(argv[1],stream1[0]);
             syslog(LOG_ALERT,"log_helper finished, terminating\n");
 	    exit(1);
-	    } 
+	    }
+        
+        name = strrchr(argv[1], '/');
+        if (name && *name != '\0') {
+          pidfile = malloc(strlen("/var/run/") + strlen(name) + strlen(".pid") + 1);
+          if (pidfile) {
+            strcpy(pidfile, "/var/run/");
+            strcat(pidfile, name);
+            strcat(pidfile, ".pid");
+            remove(pidfile);
+            pfh = pidfile_open(pidfile, 0600, &pid);
+            if (pfh) {
+                pidfile_write(pfh);
+                pidfile_close(pfh);
+            }
+            free(pidfile);
+          }
+        }
         for(;;) {
 	    /* If we got a HUP signal, send it to the child */
 	    if(got_hup_signal == 1) {
