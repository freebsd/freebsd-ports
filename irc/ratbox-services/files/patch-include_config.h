--- include/config.h.orig	Tue Aug 23 20:41:19 2005
+++ include/config.h	Sat Jan 28 22:08:14 2006
@@ -5,11 +5,13 @@
  * IMPORTANT: if you alter the directories these files go to,
  *            you must create those paths yourself.
  */
+#define DBDIR		"%%DBDIR%%"
+
 #define CONF_PATH	SYSCONFDIR "/ratbox-services.conf"
 #define PID_PATH	RUNDIR "/ratbox-services.pid"
 #define LOG_PATH	LOGDIR "/ratbox-services.log"
 #define HELP_PATH       HELPDIR
-#define DB_PATH		SYSCONFDIR "/ratbox-services.db"
+#define DB_PATH		DBDIR "/ratbox-services.db"
 
 /* SMALL_NETWORK
  * If your network is fairly small, enable this to save some memory.
