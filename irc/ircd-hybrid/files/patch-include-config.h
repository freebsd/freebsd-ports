--- include/config.h.orig	Thu Feb  6 01:46:11 2003
+++ include/config.h	Thu Jan 29 20:16:13 2004
@@ -90,7 +90,9 @@
 /*#define IRCD_PREFIX     "IRCD$BASEDIR:"*/
 #define DPATH           "IRCD$BASEDIR:"
 #define BINPATH         "IRCD$BINDIR:"
+/*
 #define ETCPATH         "IRCD$CONFDIR:"
+*/
 #define LOGPATH         "IRCD$LOGDIR:"
 
 #undef  MODPATH
@@ -134,13 +136,13 @@
 /* dirs */
 #define DPATH   IRCD_PREFIX                                                     
 #define BINPATH IRCD_PREFIX "/bin/"
-#define MODPATH IRCD_PREFIX "/modules/"
-#define AUTOMODPATH IRCD_PREFIX "/modules/autoload/"
-#define MSGPATH IRCD_PREFIX "/messages/"
-#define ETCPATH IRCD_PREFIX "/etc"
+#define MODPATH IRCD_PREFIX "/share/ircd-hybrid-7.0/modules/"
+#define AUTOMODPATH IRCD_PREFIX "/share/ircd-hybrid-7.0/modules/autoload/"
+#define MSGPATH IRCD_PREFIX "/share/ircd-hybrid-7.0/messages/"
+#define ETCPATH IRCD_PREFIX "/etc/ircd-hybrid"
 #define LOGPATH IRCD_PREFIX "/logs"
-#define UHPATH   IRCD_PREFIX "/help/users"
-#define HPATH  IRCD_PREFIX "/help/opers"
+#define UHPATH   IRCD_PREFIX "/share/ircd-hybrid-7.0/help/users"
+#define HPATH  IRCD_PREFIX "/share/ircd-hybrid-7.0/help/opers"
 
 /* files */
 #define SPATH   BINPATH "/ircd"                 /* ircd executable */
