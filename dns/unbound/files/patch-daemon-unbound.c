--- daemon/unbound.c.orig	2008-11-20 12:48:36.000000000 +0300
+++ daemon/unbound.c	2008-12-18 17:36:58.000000000 +0300
@@ -345,8 +345,6 @@
 	 * a fork error could not be printed since daemonize closed stderr.*/
 	if(cfg->use_syslog) {
 		log_init(cfg->logfile, cfg->use_syslog, cfg->chrootdir);
-		/* but syslog is not really opened by glibc until first msg */
-		log_info("open syslog, startup in progress");
 	}
 	/* if using a logfile, we cannot open it because the logfile would
 	 * be created with the wrong permissions, we cannot chown it because
@@ -516,7 +514,11 @@
 		if(!done_setup) { 
 			perform_setup(daemon, cfg, debug_mode, &cfgfile); 
 			done_setup = 1; 
-		} else log_init(cfg->logfile, cfg->use_syslog, cfg->chrootdir);
+		} else {
+			/* reopen log after HUP to facilitate log rotation */
+			if(!cfg->use_syslog)
+				log_init(cfg->logfile, 0, cfg->chrootdir);
+		}
 		/* work */
 		daemon_fork(daemon);
 
