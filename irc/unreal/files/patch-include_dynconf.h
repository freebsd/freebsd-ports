--- include/dynconf.h.orig	2014-07-26 17:42:10.000000000 +0200
+++ include/dynconf.h	2015-02-25 20:44:09.939110131 +0100
@@ -204,7 +204,11 @@
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
