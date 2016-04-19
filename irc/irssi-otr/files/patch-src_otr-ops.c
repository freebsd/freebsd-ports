--- src/otr-ops.c	2014-02-12 18:50:45.000000000 -0600
+++ src/otr-ops.c	2016-04-07 17:35:00.000000000 +0530
@@ -21,6 +21,7 @@
 
 #include "key.h"
 #include "module.h"
+#include "irssi-version.h"
 
 static OtrlPolicy OTR_DEFAULT_POLICY =
 	OTRL_POLICY_MANUAL | OTRL_POLICY_WHITESPACE_START_AKE;
@@ -206,8 +207,13 @@ static void ops_handle_msg_event(void *opdata, OtrlMessageEvent msg_event,
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
