--- ./include/config.h.orig	Wed Sep  5 20:08:21 2007
+++ ./include/config.h	Tue Apr 22 02:20:19 2008
@@ -54,15 +54,17 @@
 #define LOGPATH LOG_DIR
 #define UHPATH   HELP_DIR "/users"
 #define HPATH  HELP_DIR "/opers"
+#define RUNPATH	"/var/run/ircd-ratbox"
+#define DBPTH "/var/db/ircd-ratbox"
 
 /* files */
 #define SPATH    BINPATH "/ircd"	/* ircd executable */
 #define SLPATH   BINPATH "/servlink"	/* servlink executable */
 #define CPATH    ETCPATH "/ircd.conf"	/* ircd.conf file */
-#define DBPATH   ETCPATH "/ban.db"
+#define DBPATH   DBPTH "/ban.db"
 #define MPATH    ETCPATH "/ircd.motd"	/* MOTD file */
 #define LPATH    LOGPATH "/ircd.log"	/* ircd logfile */
-#define PPATH    ETCPATH "/ircd.pid"	/* pid file */
+#define PPATH    RUNPATH "/ircd.pid"	/* pid file */
 #define OPATH    ETCPATH "/opers.motd"	/* oper MOTD file */
 
 /* TS6_ONLY
