--- include/config.h.orig	Sat Oct 26 10:03:41 2002
+++ include/config.h	Sat Oct 26 10:13:43 2002
@@ -38,11 +38,11 @@
 #define LANGPATH 	IRCD_PREFIX_LIB "/languages"
 #define CHANMODEPATH 	IRCD_PREFIX_LIB "/chanmodes"
 
-#define LOGFILE		IRCD_PREFIX_VAR "/logfiles/ircd.log"
-#define IRCD_PIDFILE    IRCD_PREFIX_VAR "/ircd.pid"
-#define LINKSFILE       IRCD_PREFIX_VAR "/ircd.links"
+#define LOGFILE		IRCD_PREFIX_VAR "/log/ircd.log"
+#define IRCD_PIDFILE    IRCD_PREFIX_VAR "/run/ircd.pid"
+#define LINKSFILE       IRCD_PREFIX_VAR "/run/ircd.links"
 
-#define HELPPATH	IRCD_PREFIX_DOC "/help/en_us"
+#define HELPPATH	IRCD_PREFIX_DOC "/tr-ircd/help/en_us"
 
 #define USE_FAKEHOST 1
 
