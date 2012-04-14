--- ./include/config.h.orig	2012-04-13 15:02:51.000000000 +0100
+++ ./include/config.h	2012-04-13 15:06:23.000000000 +0100
@@ -54,15 +54,17 @@
 #define LOGPATH LOG_DIR
 #define UHPATH   HELP_DIR "/users"
 #define HPATH  HELP_DIR "/opers"
+#define RUNPATH	"%%RUNDIR%%"
+#define DBPTH	"%%DBDIR%%"
 
 /* files */
 #define SPATH    BINPATH "/ircd"	/* ircd executable */
 #define CPATH    ETCPATH "/ircd.conf"	/* ircd.conf file */
-#define DBPATH   ETCPATH "/ban.db"
+#define DBPATH   DBPTH "/ban.db"
 #define MPATH    ETCPATH "/ircd.motd"	/* MOTD file */
 #define LPATH    LOGPATH "/ircd.log"	/* ircd logfile */
 #define PPATH    ETCPATH "/ircd.pid"	/* pid file */
-#define OPATH    ETCPATH "/opers.motd"	/* oper MOTD file */
+#define OPATH    RUNPATH "/opers.motd"	/* oper MOTD file */
 
 /* HANGONGOODLINK and HANGONGOODLINK
  * Often net breaks for a short time and it's useful to try to
