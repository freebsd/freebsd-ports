--- include/config.h.orig	Tue Jan  9 01:51:42 2001
+++ include/config.h	Tue Jan  9 02:03:44 2001
@@ -52,7 +52,7 @@
  * have a continuation char.
  */
 #define DEFAULT_SERVER	"[ODNet] "\
-				"irc.bitchx.com "\
+				"irc.taiwan.com "\
 			"[efnet] "\
 				"irc.total.net "\
 				"ircd.c-com.net "\
@@ -479,7 +479,7 @@
 
 #define DEFAULT_HTTP_GRAB OFF
 #define DEFAULT_HELP_WINDOW OFF
-#define DEFAULT_NICK_COMPLETION ON
+#define DEFAULT_NICK_COMPLETION OFF
 #define DEFAULT_NICK_COMPLETION_LEN 2
 #define DEFAULT_NICK_COMPLETION_TYPE 0  /* 0 1 2 */
 #define DEFAULT_NOTIFY ON
@@ -514,9 +514,9 @@
 #define DEFAULT_AINV 0
 #define DEFAULT_ANNOY_KICK OFF
 #define DEFAULT_AOP_VAR OFF
-#define DEFAULT_AUTO_AWAY ON
-#define DEFAULT_KICK_OPS ON
-#define DEFAULT_AUTO_REJOIN ON
+#define DEFAULT_AUTO_AWAY OFF
+#define DEFAULT_KICK_OPS OFF
+#define DEFAULT_AUTO_REJOIN OFF
 #define DEFAULT_DEOPFLOOD ON
 #if defined(__EMXPM__) || defined(WIN32)
 #define DEFAULT_CODEPAGE 437
@@ -757,7 +757,7 @@
 #endif
 
 #undef PARANOID		/* #define this if your paranoid about dcc hijacking */
-#undef WANT_CHAN_NICK_SERV	/* do we want to include some chan/nick/oper server commands */
+#define WANT_CHAN_NICK_SERV	/* do we want to include some chan/nick/oper server commands */
 
 /* new epic stuff */
 #define OLD_STATUS_S_EXPANDO_BEHAVIOR
