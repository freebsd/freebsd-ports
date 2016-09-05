--- include/config.h.orig	2016-09-03 19:34:06 UTC
+++ include/config.h
@@ -242,16 +242,16 @@
  * line argument. These used as the default values for options absent from the user's
  * unrealircd.conf.
  */
-#define	CPATH		"unrealircd.conf"	/* server configuration file */
-#define	MPATH		"ircd.motd"	/* server MOTD file */
-#define SMPATH          "ircd.smotd"    /* short MOTD file */
-#define RPATH   	"ircd.rules"	/* server rules file */
-#define OPATH   	"oper.motd"	/* Operators MOTD file */
-#define	LPATH		"debug.log"	/* Where the debug file lives, if DEBUGMODE */
-#define	PPATH		"ircd.pid"	/* file for server pid */
-#define VPATH		"ircd.svsmotd"	/* Services MOTD append. */
-#define BPATH		"bot.motd"	/* Bot MOTD */
-#define IRCDTUNE 	"ircd.tune"	/* tuning .. */
+#define	CPATH		"/usr/local/etc/Unreal/unrealircd.conf"	/* server configuration file */
+#define	MPATH		"/usr/local/etc/Unreal/ircd.motd"	/* server MOTD file */
+#define SMPATH		"/usr/local/etc/Unreal/ircd.smotd"	/* short MOTD file */
+#define RPATH		"/usr/local/etc/Unreal/ircd.rules"	/* server rules file */
+#define OPATH		"/usr/local/etc/Unreal/oper.motd"	/* Operators MOTD file */
+#define	LPATH		"/var/log/ircd/debug.log"	/* Where the debug file lives, if DEBUGMODE */
+#define	PPATH		"/var/run/ircd/ircd.pid"	/* file for server pid */
+#define VPATH		"/usr/local/etc/Unreal/ircd.svsmotd"	/* Services MOTD append. */
+#define BPATH		"/usr/local/etc/Unreal/bot.motd"	/* Bot MOTD */
+#define IRCDTUNE 	"/var/run/ircd/ircd.tune"	/* tuning .. */
 
 /* CHROOTDIR
  *
@@ -277,8 +277,8 @@
  * define IRC_USER to that user name.  This should only be defined if you 
  * are running as root and even then perhaps not.
  */
-/* #define IRC_USER  "<user name>" */
-/* #define IRC_GROUP "<group name>" */
+#define IRC_USER  "ircd"
+#define IRC_GROUP "ircd"
 
 
 /* SHOW_INVISIBLE_LUSERS
