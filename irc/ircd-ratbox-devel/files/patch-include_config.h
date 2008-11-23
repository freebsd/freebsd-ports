--- ./include/config.h.orig	2008-09-19 16:33:46.000000000 +0100
+++ ./include/config.h	2008-11-15 02:55:35.000000000 +0000
@@ -52,16 +52,18 @@
 #define AUTOMODPATH MODULE_DIR "/autoload/"
 #define ETCPATH ETC_DIR
 #define LOGPATH LOG_DIR
-#define UHPATH   HELP_DIR "/users"
-#define HPATH  HELP_DIR "/opers"
+#define UHPATH	HELP_DIR "/users"
+#define HPATH	HELP_DIR "/opers"
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
