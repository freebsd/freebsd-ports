--- contrib/mod_sql_tds.c.orig	2010-03-24 09:52:43.325690672 +0100
+++ contrib/mod_sql_tds.c	2010-03-24 09:53:04.995963774 +0100
@@ -567,7 +567,7 @@
     sql_log(DEBUG_WARN, "%s", "No Host Specified! \t Checking Enviroment Variable");
     server = getenv("DSQUERY");
     if(server == NULL){
-      log_pri(PR_LOG_ERR, "%s", "NO Host Specified and DSQUERY Enviroment Variable NOT Found! "
+      pr_log_pri(PR_LOG_ERR, "%s", "NO Host Specified and DSQUERY Enviroment Variable NOT Found! "
 	      "-- Shutting down!.");
       sql_log(DEBUG_WARN, "%s", "NO Host Specified and DSQUERY Enviroment Variable NOT Found! "
 		"-- Shutting down!.");
