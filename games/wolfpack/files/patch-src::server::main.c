--- src/server/main.c.orig	Tue Sep  7 23:52:39 2004
+++ src/server/main.c	Sun Oct 10 23:09:23 2004
@@ -78,6 +78,7 @@
 
 #if !defined(_WIN32)
 static int mainpid = 0;
+static char *pidfile = NULL;
 #endif
 
 /*
@@ -93,9 +94,10 @@
     time_t now;
     int flags = 0;
     int op;
-    char *config_file = NULL;
+    char *config_file = NULL, pbuf[256];
     extern char *optarg;
     s_char tbuf[256];
+    FILE *pidf;
 #ifdef POSIXSIGNALS
     struct sigaction act;
 #endif /* POSIXSIGNALS */
@@ -105,11 +107,14 @@
 #if !defined(_WIN32)
     mainpid = getpid();
 
-    while ((op = getopt(argc, argv, "D:de:psh")) != EOF) {
+    while ((op = getopt(argc, argv, "D:P:de:psh")) != EOF) {
 	switch (op) {
 	case 'D':
 	    datadir = optarg;
 	    break;
+	case 'P':
+	    pidfile = optarg;
+	    break;
 	case 'd':
 	    debug++;
 	    break;
@@ -124,7 +129,15 @@
 	    break;
 	case 'h':
 	default:
-	    printf("Usage: %s -d -p -s\n", argv[0]);
+	    fprintf(stderr, "Usage: %s -D <datadir> -d -e <configfile> -p -s\n"
+			    "	-D Use the specified data dir\n"
+			    "	-P Write out the PID to the specified file\n"
+			    "	-d Increase debugging\n"
+			    "	-e Use the specified config file\n"
+			    "	-p Print thread debugging information\n"
+			    "	-s Print thread info, and do stack checks\n",
+		    argv[0]);
+
 	    return 0;
 	}
     }
@@ -134,13 +147,6 @@
 	config_file = tbuf;
     }
 
-    logerror("------------------------------------------------------");
-#if !defined(_WIN32)
-    logerror("Empire server (pid %d) started", getpid());
-#else
-    logerror("Empire server started");
-#endif /* _WIN32 */
-
 #if defined(_WIN32)
     loc_NTInit();
 #endif
@@ -193,6 +199,32 @@
     signal(SIGPIPE, SIG_IGN);
 #endif /* POSIXSIGNALS */
 #endif /* _WIN32 */
+
+#if !defined(_WIN32)
+    if (pidfile != NULL) {
+	if ((pidf = fopen(pidfile, "a")) == NULL) {
+	    logerror("Unable to open PID file %s - %s", pidfile, strerror(errno));
+	    exit(1);
+	} else {
+	    op = snprintf(pbuf, sizeof(pbuf), "%d\n", getpid());
+	    if (fwrite(pbuf, 1, op, pidf) != op) {
+		unlink(pidfile);
+		logerror("Unable to write PID file %s - %s", pidfile, strerror(errno));
+		exit(1);
+	    }
+	    fclose(pidf);
+
+	}
+    }
+#endif
+
+    logerror("------------------------------------------------------");
+#if !defined(_WIN32)
+    logerror("Empire server (pid %d) started", getpid());
+#else
+    logerror("Empire server started");
+#endif /* _WIN32 */
+
     empth_init((char **)&player, flags);
     time(&now);
 #if !defined(_WIN32)
@@ -312,9 +344,13 @@
     signal(SIGFPE, SIG_DFL);
 #endif /* POSIXSIGNALS */
 #endif /* _WIN32 */
-    logerror("server received fatal signal %d", sig);
+logerror("server received fatal signal %d", sig);
     log_last_commands();
     close_files();
+
+    if (pidfile != NULL)
+	unlink(pidfile);
+    
     _exit(0);
 }
 
@@ -381,6 +417,9 @@
     else
 	logerror("Server shutting down at Deity's request");
     close_files();
+    if (pidfile != NULL)
+	unlink(pidfile);
+    
     _exit(0);
 }
 
