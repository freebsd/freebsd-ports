--- src/module.c.orig	2016-12-07 21:24:08 UTC
+++ src/module.c
@@ -33,6 +33,7 @@
 #include "otr.h"
 #include "otr-formats.h"
 #include "utils.h"
+#include "irssi-version.h"
 
 GCRY_THREAD_OPTION_PTHREAD_IMPL;
 
@@ -91,8 +92,13 @@ end:
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
@@ -107,7 +113,11 @@ void sig_message_private(SERVER_REC *ser
 
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
