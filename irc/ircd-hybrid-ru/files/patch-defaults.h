--- include/defaults.h.ORIG	Mon Oct 16 13:32:18 2006
+++ include/defaults.h	Mon Oct 16 13:34:28 2006
@@ -51,11 +51,11 @@
 #define DPATH       IRCD_PREFIX                                                     
 #define BINPATH     IRCD_PREFIX "/bin/"
 #define MSGPATH     IRCD_PREFIX "/messages/"
-#define ETCPATH     IRCD_PREFIX "/etc"
+#define ETCPATH     IRCD_PREFIX "/etc/ircd-hybrid-ru/"
 #define CPPATH      ETCPATH     "/codepages/"
-#define LOGPATH     IRCD_PREFIX "/logs"
-#define MODPATH     IRCD_PREFIX "/modules/"
-#define AUTOMODPATH IRCD_PREFIX "/modules/autoload/"
+#define LOGPATH     		"/var/log/ircd-hybrid-ru/"
+#define MODPATH     IRCD_PREFIX "/lib/ircd-hybrid-ru-modules/"
+#define AUTOMODPATH IRCD_PREFIX "/lib/ircd-hybrid-ru-modules/autoload/"
 
 /* files */
 #define SPATH   BINPATH "/ircd"                 /* ircd executable */
