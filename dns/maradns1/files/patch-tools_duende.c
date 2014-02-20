--- tools/duende.c.orig 2008-08-03 20:10:49.000000000 +0200
+++ tools/duende.c      2010-09-30 01:46:03.000000000 +0200
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
 
@@ -61,13 +64,24 @@
 
 void log_helper(char *name,int stdout_fd) {
     char out_buf[1024];
+    
+    /* Prefix MaraDNS syslog messages with ident of "maradns:" 
+       instead of "/usr/local/sbin/maradns:" */
+    char *needle, *ident;
+    needle = strrchr(name,'/');
+    /* needle found and not at the end of string */
+    if (needle && *(needle + 1) != '\0') {
+        ident = needle + 1;
+    } else {
+        ident = name;
+    }       
 
     /* We can't use our signal handlers because fgets is blocking */
     signal(SIGTERM,SIG_DFL);
     signal(SIGHUP,SIG_DFL);
 
     /* Open up the sys log */
-    openlog(name,0,LOG_DAEMON);
+    openlog(ident,0,LOG_DAEMON);
 
     /* Drop all privileges */
     if(chdir(DUENDE_CHROOT_DIR) != 0) {
@@ -146,6 +160,10 @@
     int exit_status;
     pid_t pid, log_pid;
     int stream1[2]; /* Used for piping */
+    struct pidfh *pfh;
+    char *name;
+    char *pidfile;
+
     if(argv[0] == NULL || argv[1] == NULL) {
         printf("Usage: duende [program] [arguments]\n");
         exit(1);
@@ -210,6 +228,23 @@
             syslog(LOG_ALERT,"log_helper finished, terminating\n");
             exit(1);
             }
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
+
         for(;;) {
             /* If we got a HUP signal, send it to the child */
             if(got_hup_signal == 1) {
