--- include/config.h.orig	Tue Jul  1 11:01:18 2003
+++ include/config.h	Tue Feb  6 15:08:49 2007
@@ -36,10 +36,10 @@
 #define SSL_CERTIFICATE	IRCD_PREFIX_ETC	"/ircd.cert"
 #define SSL_KEY		IRCD_PREFIX_ETC	"/ircd.key"
 
-#define RANDFILE	IRCD_PREFIX_VAR "/lib/" BASENAME "/ircd.rand"	/* used to make openssl keygen faster */
-#define ENTROPYFILE	IRCD_PREFIX_VAR "/lib/" BASENAME "/ircd.entropy"
-#define LINKSFILE       IRCD_PREFIX_VAR "/lib/" BASENAME "/ircd.links"
-#define IRCD_PIDFILE    IRCD_PREFIX_VAR "/run/" BASENAME "/ircd.pid"
+#define RANDFILE	IRCD_PREFIX_VAR "/ircd.rand"	/* used to make openssl keygen faster */
+#define ENTROPYFILE	IRCD_PREFIX_VAR "/ircd.entropy"
+#define LINKSFILE       IRCD_PREFIX_VAR "/ircd.links"
+#define IRCD_PIDFILE    IRCD_PREFIX_VAR "/ircd.pid"
 
 #define MODPATH 	IRCD_PREFIX_LIB "/modules"
 #define LANGPATH 	IRCD_PREFIX_LIB "/languages"
@@ -47,7 +47,7 @@
 #define CONTRIBPATH	IRCD_PREFIC_LIB "/contrib"
 #define TOOLMODPATH	IRCD_PREFIX_LIB "/tools"
 
-#define HELPPATH	IRCD_PREFIX_DOC "/help"
+#define HELPPATH	IRCD_PREFIX_DOC "/" BASENAME "/help"
 
 #define CLIENTS_PREALLOCATE     2048
 #define CHANNELS_PREALLOCATE    2048
