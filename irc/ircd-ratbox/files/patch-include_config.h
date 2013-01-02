--- ./include/config.h.orig	2012-03-16 05:33:15.000000000 +0000
+++ ./include/config.h	2013-01-01 05:56:38.000000000 +0000
@@ -54,14 +54,16 @@
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
-#define PPATH    ETCPATH "/ircd.pid"	/* pid file */
+#define PPATH    RUNPATH "/ircd.pid"	/* pid file */
 #define OPATH    ETCPATH "/opers.motd"	/* oper MOTD file */
 
 /* HANGONGOODLINK and HANGONGOODLINK
