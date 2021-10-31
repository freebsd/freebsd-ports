--- ext-src/swoole_admin_server.cc.orig	2021-10-29 10:11:22 UTC
+++ ext-src/swoole_admin_server.cc
@@ -171,8 +171,44 @@ static json get_socket_info(int fd) {
         };
         return return_value.dump();
     }
+#if defined(__FreeBSD__)
     json jinfo{
         {"state", info.tcpi_state},
+        {"ca_state", info.__tcpi_ca_state},
+        {"retransmits", info.__tcpi_retransmits},
+        {"probes", info.__tcpi_probes},
+        {"backoff", info.__tcpi_backoff},
+        {"options", info.tcpi_options},
+        {"snd_wscale", uint8_t(info.tcpi_snd_wscale)},
+        {"rcv_wscale", uint8_t(info.tcpi_rcv_wscale)},
+        {"rto", info.tcpi_rto},
+        {"ato", info.__tcpi_ato},
+        {"snd_mss", info.tcpi_snd_mss},
+        {"rcv_mss", info.tcpi_rcv_mss},
+        {"unacked", info.__tcpi_unacked},
+        {"sacked", info.__tcpi_sacked},
+        {"lost", info.__tcpi_lost},
+        {"retrans", info.__tcpi_retrans},
+        {"fackets", info.__tcpi_fackets},
+        {"last_data_sent", info.__tcpi_last_data_sent},
+        {"last_ack_sent", info.__tcpi_last_ack_sent},
+        {"last_data_recv", info.tcpi_last_data_recv},
+        {"last_ack_recv", info.__tcpi_last_ack_recv},
+        {"pmtu", info.__tcpi_pmtu},
+        {"rcv_ssthresh", info.__tcpi_rcv_ssthresh},
+        {"rtt", info.tcpi_rtt},
+        {"rttvar", info.tcpi_rttvar},
+        {"snd_ssthresh", info.tcpi_snd_ssthresh},
+        {"snd_cwnd", info.tcpi_snd_cwnd},
+        {"advmss", info.__tcpi_advmss},
+        {"reordering", info.__tcpi_reordering},
+        {"rcv_rtt", info.__tcpi_rcv_rtt},
+        {"rcv_space", info.tcpi_rcv_space},
+        {"total_retrans", 0},
+    };
+#else
+    json jinfo{
+        {"state", info.tcpi_state},
         {"ca_state", info.tcpi_ca_state},
         {"retransmits", info.tcpi_retransmits},
         {"probes", info.tcpi_probes},
@@ -205,6 +241,7 @@ static json get_socket_info(int fd) {
         {"rcv_space", info.tcpi_rcv_space},
         {"total_retrans", info.tcpi_total_retrans},
     };
+#endif
     return jinfo;
 }
 #endif
