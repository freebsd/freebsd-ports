--- include/config.h.orig	Sat May  4 15:57:33 2002
+++ include/config.h	Sat May  4 15:59:21 2002
@@ -33,12 +33,12 @@
 #define KLINEFILE	IRCD_PREFIX "/etc/kline.conf"
 #define	MOTD		IRCD_PREFIX "/etc/ircd.motd"
 #define	SHORTMOTD	IRCD_PREFIX "/etc/ircd.smotd"
-#define	LOGFILE		IRCD_PREFIX "/etc/ircd.log"
+#define	LOGFILE		            "/var/log/ircd.log"
 #define LINKSFILE	IRCD_PREFIX "/etc/ircd.links"
 
-#define IRCD_PIDFILE    IRCD_PREFIX "/tmp/ircd.pid"
+#define IRCD_PIDFILE                "/var/run/ircd.pid"
 
-#define HELPPATH	IRCD_PREFIX "/help/en_us"
+#define HELPPATH	IRCD_PREFIX "/share/tr-ircd/help/en_us"
 
 /*
  * LOCKFILE - Exclusive use of ircd.conf and kline.conf during writes
@@ -51,7 +51,7 @@
  * minutes have elapsed.
  */
 
-#define LOCKFILE 	IRCD_PREFIX "/tmp/ircd.conf.lock"
+#define LOCKFILE 	            "/tmp/ircd.conf.lock"
 
 #define USE_FAKEHOST
 
