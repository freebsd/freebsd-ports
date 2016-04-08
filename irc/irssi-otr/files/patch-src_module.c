--- src/module.c	2014-02-12 18:50:45.000000000 -0600
+++ src/module.c	2016-04-07 17:35:00.000000000 +0530
@@ -32,6 +32,7 @@
 #include "otr.h"
 #include "otr-formats.h"
 #include "utils.h"
+#include "irssi-version.h"
 
 GCRY_THREAD_OPTION_PTHREAD_IMPL;
 
@@ -90,8 +91,13 @@ static void sig_server_sendmsg(SERVER_REC *server, const char *target,
 /*
  * Pipes all incoming private messages through OTR
  */
+#if IRSSI_VERSION_DATE > 20141206
 void sig_message_private(SERVER_REC *server, const char *msg,
-		const char *nick, const char *address)
+		const char *nick, const char *address, const char *target)
+#else
+void sig_message_private(SERVER_REC *server, const char *msg,
+                const char *nick, const char *address)
+#endif
 {
 	int ret;
 	char *new_msg = NULL;
@@ -106,7 +112,11 @@ void sig_message_private(SERVER_REC *server, const char *msg,
 
 	if (!new_msg) {
 		/* This message was not OTR */
-		signal_continue(4, server, msg, nick, address);
+#if IRSSI_VERSION_DATE > 20141206
+		signal_continue(5, server, msg, nick, address, target);
+#else
+                signal_continue(4, server, msg, nick, address);
+#endif
 	} else {
 		/*
 		 * Check for /me IRC marker and if so, handle it so the user does not
@@ -371,3 +371,13 @@ void otr_deinit(void)
  
 	theme_unregister();
 }
+
+#ifdef IRSSI_ABI_VERSION
+/*
+ * irssi abicheck()
+ */
+void otr_abicheck(int *version)
+{
+	*version = IRSSI_ABI_VERSION;
+}
+#endif
 
