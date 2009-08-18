--- include/config.h	2009-04-13 13:03:57.000000000 +0200
+++ include/config.h	2009-08-18 16:16:39.000000000 +0200
@@ -210,16 +210,16 @@
  * these are only the recommened names and paths. Change as needed.
  * You must define these to something, even if you don't really want them.
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
