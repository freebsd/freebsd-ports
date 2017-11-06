--- src/otr-ops.c.orig	2016-12-07 21:24:08 UTC
+++ src/otr-ops.c
@@ -21,6 +21,7 @@
 
 #include "key.h"
 #include "module.h"
+#include "irssi-version.h"
 
 static OtrlPolicy OTR_DEFAULT_POLICY =
 	OTRL_POLICY_MANUAL | OTRL_POLICY_WHITESPACE_START_AKE;
@@ -206,8 +207,13 @@ static void ops_handle_msg_event(void *o
 		 * submit a patch or email me a better way.
 		 */
 		signal_remove("message private", (SIGNAL_FUNC) sig_message_private);
-		signal_emit("message private", 4, server, message, username,
+#if IRSSI_VERSION_DATE > 20141206
+		signal_emit("message private", 5, server, message, username, server->nick,
 				IRSSI_CONN_ADDR(server));
+#else
+                signal_emit("message private", 4, server, message, username,
+                                IRSSI_CONN_ADDR(server));
+#endif
 		signal_add_first("message private", (SIGNAL_FUNC) sig_message_private);
 		break;
 	case OTRL_MSGEVENT_RCVDMSG_UNRECOGNIZED:
