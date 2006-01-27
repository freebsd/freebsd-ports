--- include/config.h.orig	Thu Jan 20 11:04:40 2005
+++ include/config.h	Fri Jan 27 02:25:37 2006
@@ -56,6 +56,7 @@
 #define LOGPATH LOG_DIR
 #define UHPATH   HELP_DIR "/users"
 #define HPATH  HELP_DIR "/opers"
+#define RUNPATH "%%RUNDIR%%"
 
 /* files */
 #define SPATH    BINPATH "/ircd"	/* ircd executable */
@@ -68,7 +69,7 @@
 #define RPATH    ETCPATH "/ircd.rsa"	/* ircd rsa private keyfile */
 #define MPATH    ETCPATH "/ircd.motd"	/* MOTD file */
 #define LPATH    LOGPATH "/ircd.log"	/* ircd logfile */
-#define PPATH    ETCPATH "/ircd.pid"	/* pid file */
+#define PPATH    RUNPATH "/ircd.pid"	/* pid file */
 #define OPATH    ETCPATH "/opers.motd"	/* oper MOTD file */
 
 /* IGNORE_BOGUS_TS
