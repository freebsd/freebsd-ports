--- include/defaults.h.orig	Fri Dec  9 00:52:49 2005
+++ include/defaults.h	Mon Jan  9 00:44:02 2006
@@ -42,19 +42,11 @@
  * BINPATH     = directory for binary files
  * MSGPATH     = directory for language files
  * ETCPATH     = directory for configuration files
- * LOGPATH     = directory for logfiles
- * MODPATH     = directory for modules
- * AUTOMODPATH = directory for autoloaded modules
  */
 
 /* dirs */
 #define DPATH       IRCD_PREFIX                                                     
 #define BINPATH     IRCD_PREFIX "/bin/"
-#define MSGPATH     IRCD_PREFIX "/messages/"
-#define ETCPATH     IRCD_PREFIX "/etc"
-#define LOGPATH     IRCD_PREFIX "/logs"
-#define MODPATH     IRCD_PREFIX "/modules/"
-#define AUTOMODPATH IRCD_PREFIX "/modules/autoload/"
 
 /* files */
 #define SPATH   BINPATH "/ircd"                 /* ircd executable */
@@ -70,7 +62,7 @@
 #define RKPATH  ETCPATH "/rkline.conf"
 #define MPATH   ETCPATH "/ircd.motd"            /* MOTD file */
 #define LPATH   LOGPATH "/ircd.log"             /* ircd logfile */
-#define PPATH   ETCPATH "/ircd.pid"             /* pid file */
+#define PPATH   "/var/run/ircd/ircd.pid"        /* pid file */
 #define OPATH   ETCPATH "/opers.motd"           /* oper MOTD file */
 #define LIPATH  ETCPATH "/links.txt"            /* cached links file */
 
