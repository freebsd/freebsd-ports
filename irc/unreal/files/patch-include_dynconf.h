--- include/dynconf.h.orig	2014-07-26 15:42:10 UTC
+++ include/dynconf.h
@@ -204,7 +204,11 @@ extern MODVAR aConfiguration iConf;
 #define SHOWCONNECTINFO			iConf.show_connect_info
 #define OPER_ONLY_STATS			iConf.oper_only_stats
 #define ANTI_SPAM_QUIT_MSG_TIME		iConf.anti_spam_quit_message_time
+#ifdef HAVE_RAND_EGD
 #define USE_EGD				iConf.use_egd
+#else
+#define USE_EGD				0
+#endif
 #define EGD_PATH			iConf.egd_path
 
 #define ircnetwork			iConf.network.x_ircnetwork
