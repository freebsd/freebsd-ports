--- bforce/bforce.c	Thu Nov 21 23:22:55 2002
+++ bforce/bforce.c	Sat Apr  3 21:47:04 2004
@@ -414,12 +419,12 @@
 		}
 	}
 	
-	if( (rc = log_open(log_getfilename(LOG_FILE_SESSION), NULL, NULL)) )
+/*	if( (rc = log_open(log_getfilename(LOG_FILE_SESSION), NULL, NULL)) )
 	{
 		log("can't continue without logging");
 		gotoexit(BFERR_FATALERROR);
 	}
-	
+*/	
 	/* Process primary config file */
 	if( opts.confname && *opts.confname )
 		rc = conf_readconf(opts.confname, 0);
@@ -433,7 +438,7 @@
 		(void)conf_readconf(opts.incname, 1);
 	
 	/* Reopen log file if it was defined in config */
-	if( log_reopen(log_getfilename(LOG_FILE_SESSION), NULL, NULL) )
+	if( log_open(log_getfilename(LOG_FILE_SESSION), NULL, NULL) )
 	{
 		log("can't continue without logging");
 		gotoexit(BFERR_FATALERROR);
