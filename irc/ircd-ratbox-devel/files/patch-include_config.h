--- ./include/config.h.orig	2008-06-09 19:32:50.000000000 +0100
+++ ./include/config.h	2008-06-29 14:51:42.000000000 +0100
@@ -54,15 +54,17 @@
 #define LOGPATH LOG_DIR
 #define UHPATH   HELP_DIR "/users"
 #define HPATH  HELP_DIR "/opers"
+#define RUNPATH	"%%RUNDIR%%"
+#define DBPTH "%%DBDIR%%"
 
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
 
 /* HANGONGOODLINK and HANGONGOODLINK
