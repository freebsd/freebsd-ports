--- ./include/config.h.orig	2013-11-24 20:24:26.000000000 +0100
+++ ./include/config.h	2014-05-23 00:34:32.000000000 +0200
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
+#define	CPATH		"%%PREFIX%%/etc/Unreal/unrealircd.conf"	/* server configuration file */
+#define	MPATH		"%%PREFIX%%/etc/Unreal/ircd.motd"	/* server MOTD file */
+#define SMPATH		"%%PREFIX%%/etc/Unreal/ircd.smotd"	/* short MOTD file */
+#define RPATH		"%%PREFIX%%/etc/Unreal/ircd.rules"	/* server rules file */
+#define OPATH		"%%PREFIX%%/etc/Unreal/oper.motd"	/* Operators MOTD file */
+#define	LPATH		"%%LOGDIR%%/debug.log"	/* Where the debug file lives, if DEBUGMODE */
+#define	PPATH		"%%RUNDIR%%/ircd.pid"	/* file for server pid */
+#define VPATH		"%%PREFIX%%/etc/Unreal/ircd.svsmotd"	/* Services MOTD append. */
+#define BPATH		"%%PREFIX%%/etc/Unreal/bot.motd"	/* Bot MOTD */
+#define IRCDTUNE 	"%%RUNDIR%%/ircd.tune"	/* tuning .. */
 
 /* CHROOTDIR
  *
@@ -277,8 +277,8 @@
  * define IRC_USER to that user name.  This should only be defined if you 
  * are running as root and even then perhaps not.
  */
-/* #define IRC_USER  "<user name>" */
-/* #define IRC_GROUP "<group name>" */
+#define IRC_USER  "%%USERS%%"
+#define IRC_GROUP "%%GROUPS%%"
 
 
 /* SHOW_INVISIBLE_LUSERS
