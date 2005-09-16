--- include/defaults.h.orig	Sat Oct  4 15:31:17 2003
+++ include/defaults.h	Sat Jul 23 14:00:15 2005
@@ -41,17 +41,11 @@
  * DPATH       = root directory of installation,
  * BINPATH     = directory for binary files,
  * ETCPATH     = directory for configuration files,
- * LOGPATH     = directory for logfiles,
- * MSGPATH     = directory for language files.
  */
 
 /* dirs */
 #define DPATH   IRCD_PREFIX                                                     
 #define BINPATH IRCD_PREFIX "/bin/"
-#define MSGPATH IRCD_PREFIX "/messages/"
-#define ETCPATH IRCD_PREFIX "/etc"
-#define LOGPATH IRCD_PREFIX "/logs"
-#define MODPATH IRCD_PREFIX "/modules/"
 
 /* files */
 #define SPATH   BINPATH "/ircd"                 /* ircd executable */
@@ -65,7 +59,7 @@
 #define XPATH   ETCPATH "/xline.conf"           /* xline file */
 #define MPATH   ETCPATH "/ircd.motd"            /* MOTD file */
 #define LPATH   LOGPATH "/ircd.log"             /* ircd logfile */
-#define PPATH   ETCPATH "/ircd.pid"             /* pid file */
+#define PPATH   "/var/run/ircd/ircd.pid"        /* pid file */
 #define OPATH   ETCPATH "/opers.motd"           /* oper MOTD file */
 #define LIPATH  ETCPATH "/links.txt"            /* cached links file */
 
