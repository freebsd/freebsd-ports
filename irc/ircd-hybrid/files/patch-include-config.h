--- include/config.h.ori	Wed Jan 28 01:57:26 2004
+++ include/config.h	Wed Jan 28 02:03:47 2004
@@ -93,8 +93,10 @@
 #define ETCPATH         "IRCD$CONFDIR:"
 #define LOGPATH         "IRCD$LOGDIR:"
 
+/*
 #undef  MODPATH
 #undef  AUTOMODPATH
+*/
 #undef  MSGPATH
 
 #define SPATH   BINPATH "IRCD.EXE"              /* server executable */
@@ -134,8 +136,10 @@
 /* dirs */
 #define DPATH   IRCD_PREFIX                                                     
 #define BINPATH IRCD_PREFIX "/bin/"
+/*
 #define MODPATH IRCD_PREFIX "/modules/"
 #define AUTOMODPATH IRCD_PREFIX "/modules/autoload/"
+*/
 #define MSGPATH IRCD_PREFIX "/messages/"
 #define ETCPATH IRCD_PREFIX "/etc"
 #define LOGPATH IRCD_PREFIX "/logs"
