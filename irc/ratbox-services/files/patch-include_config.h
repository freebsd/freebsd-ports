--- ./include/config.h.orig	2008-05-20 20:11:01.000000000 +0100
+++ ./include/config.h	2008-06-26 15:50:19.000000000 +0100
@@ -5,11 +5,12 @@
  * IMPORTANT: if you alter the directories these files go to,
  *            you must create those paths yourself.
  */
+#define DBDIR		"%%DBDIR%%"
 #define CONF_PATH	SYSCONFDIR "/ratbox-services.conf"
 #define PID_PATH	RUNDIR "/ratbox-services.pid"
 #define LOG_PATH	LOGDIR "/ratbox-services.log"
 #define HELP_PATH       HELPDIR
-#define DB_PATH		SYSCONFDIR "/ratbox-services.db"
+#define DB_PATH		DBDIR "/ratbox-services.db"
 
 /* SMALL_NETWORK
  * If your network is fairly small, enable this to save some memory.
