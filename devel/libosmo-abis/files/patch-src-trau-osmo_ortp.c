--- src/trau/osmo_ortp.c.orig	2015-09-21 08:55:12 UTC
+++ src/trau/osmo_ortp.c
@@ -93,7 +93,7 @@ static int ortp_to_osmo_lvl(OrtpLogLevel
 	return LOGL_ERROR;
 }
 
-static void my_ortp_logfn(OrtpLogLevel lev, const char *fmt,
+static void my_ortp_logfn(const char *domain, OrtpLogLevel lev, const char *fmt,
 			  va_list args)
 {
 	osmo_vlogp(DLMIB, ortp_to_osmo_lvl(lev), __FILE__, 0,
@@ -267,7 +267,7 @@ void osmo_rtp_init(void *ctx)
 	tall_rtp_ctx = ctx;
 	ortp_set_memory_functions(&osmo_ortp_memfn);
 	ortp_init();
-	ortp_set_log_level_mask(0xffff);
+	ortp_set_log_level_mask(NULL, 0xffff);
 	ortp_set_log_handler(my_ortp_logfn);
 	create_payload_types();
 }
@@ -326,16 +326,16 @@ struct osmo_rtp_socket *osmo_rtp_socket_
 
 	rtp_session_signal_connect(rs->sess, "ssrc_changed",
 				   (RtpCallback) ortp_sig_cb_ssrc,
-				   (unsigned long) rs);
+				   rs);
 	rtp_session_signal_connect(rs->sess, "payload_type_changed",
 				   (RtpCallback) ortp_sig_cb_pt,
-				   (unsigned long) rs);
+				   rs);
 	rtp_session_signal_connect(rs->sess, "network_error",
 				   (RtpCallback) ortp_sig_cb_net,
-				   (unsigned long) rs);
+				   rs);
 	rtp_session_signal_connect(rs->sess, "timestamp_jump",
 				   (RtpCallback) ortp_sig_cb_ts,
-				   (unsigned long) rs);
+				   rs);
 
 	/* initialize according to the RFC */
 	rtp_session_set_seq_number(rs->sess, random());
