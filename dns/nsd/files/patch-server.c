--- server.c.orig	2021-04-06 11:23:15 UTC
+++ server.c
@@ -95,16 +95,22 @@
 static void
 log_addr(const char* descr,
 #ifdef INET6
-	struct sockaddr_storage* addr,
+	struct sockaddr_storage* addr
 #else
-	struct sockaddr_in* addr,
+	struct sockaddr_in* addr
 #endif
-	short family)
+	)
 {
 	char str_buf[64];
 	if(verbosity < 6)
 		return;
-	if(family == AF_INET) {
+	if(
+#ifdef INET6
+		addr->ss_family == AF_INET
+#else
+		addr->sin_family == AF_INET
+#endif
+		) {
 		struct sockaddr_in* s = (struct sockaddr_in*)addr;
 		inet_ntop(AF_INET, &s->sin_addr.s_addr, str_buf, sizeof(str_buf));
 		VERBOSITY(6, (LOG_INFO, "%s: address is: %s, port is: %d", descr, str_buf, ntohs(s->sin_port)));
@@ -857,10 +863,10 @@ set_nonblock(struct nsd_socket *sock)
 	return 1;
 }
 
+#ifdef INET6
 static int
 set_ipv6_v6only(struct nsd_socket *sock)
 {
-#ifdef INET6
 #ifdef IPV6_V6ONLY
 	int on = 1;
 	const char *socktype =
@@ -875,16 +881,19 @@ set_ipv6_v6only(struct nsd_socket *sock)
 	log_msg(LOG_ERR, "setsockopt(..., IPV6_V6ONLY, ...) failed for %s: %s",
 		socktype, strerror(errno));
 	return -1;
+#else
+	(void)sock;
 #endif /* IPV6_V6ONLY */
-#endif /* INET6 */
 
 	return 0;
 }
+#endif /* INET6 */
 
+#ifdef INET6
 static int
 set_ipv6_use_min_mtu(struct nsd_socket *sock)
 {
-#if defined(INET6) && (defined(IPV6_USE_MIN_MTU) || defined(IPV6_MTU))
+#if defined(IPV6_USE_MIN_MTU) || defined(IPV6_MTU)
 #if defined(IPV6_USE_MIN_MTU)
 	/* There is no fragmentation of IPv6 datagrams during forwarding in the
 	 * network. Therefore we do not send UDP datagrams larger than the
@@ -917,6 +926,7 @@ set_ipv6_use_min_mtu(struct nsd_socket *sock)
 
 	return 0;
 }
+#endif /* INET6 */
 
 static int
 set_ipv4_no_pmtu_disc(struct nsd_socket *sock)
@@ -2864,7 +2874,7 @@ add_tcp_handler(
 		data->tls_accept = 1;
 		if(verbosity >= 2) {
 			char buf[48];
-			addrport2str((struct sockaddr_storage*)&sock->addr.ai_addr, buf, sizeof(buf));
+			addrport2str((void*)(struct sockaddr_storage*)&sock->addr.ai_addr, buf, sizeof(buf));
 			VERBOSITY(2, (LOG_NOTICE, "setup TCP for TLS service on interface %s", buf));
 		}
 	} else {
@@ -3339,9 +3349,9 @@ handle_udp(int fd, short event, void* arg)
 		/*
 		 * sending UDP-query with server address (local) and client address to dnstap process
 		 */
-		log_addr("query from client", &q->addr, data->socket->addr.ai_family);
-		log_addr("to server (local)", &data->socket->addr.ai_addr, data->socket->addr.ai_family);
-		dt_collector_submit_auth_query(data->nsd, &data->socket->addr.ai_addr, &q->addr, q->addrlen,
+		log_addr("query from client", &q->addr);
+		log_addr("to server (local)", (void*)&data->socket->addr.ai_addr);
+		dt_collector_submit_auth_query(data->nsd, (void*)&data->socket->addr.ai_addr, &q->addr, q->addrlen,
 			q->tcp, q->packet);
 #endif /* USE_DNSTAP */
 
@@ -3378,9 +3388,9 @@ handle_udp(int fd, short event, void* arg)
 			/*
 			 * sending UDP-response with server address (local) and client address to dnstap process
 			 */
-			log_addr("from server (local)", &data->socket->addr.ai_addr, data->socket->addr.ai_family);
-			log_addr("response to client", &q->addr, data->socket->addr.ai_family);
-			dt_collector_submit_auth_response(data->nsd, &data->socket->addr.ai_addr,
+			log_addr("from server (local)", (void*)&data->socket->addr.ai_addr);
+			log_addr("response to client", &q->addr);
+			dt_collector_submit_auth_response(data->nsd, (void*)&data->socket->addr.ai_addr,
 				&q->addr, q->addrlen, q->tcp, q->packet,
 				q->zone);
 #endif /* USE_DNSTAP */
@@ -3448,7 +3458,7 @@ handle_udp(int fd, short event, void* arg)
 			   errno != EAGAIN) {
 				const char* es = strerror(errno);
 				char a[64];
-				addrport2str(&queries[i]->addr, a, sizeof(a));
+				addrport2str((void*)&queries[i]->addr, a, sizeof(a));
 				log_msg(LOG_ERR, "sendmmsg [0]=%s count=%d failed: %s", a, (int)(recvcount-i), es);
 			}
 #ifdef BIND8_STATS
@@ -3685,9 +3695,9 @@ handle_tcp_reading(int fd, short event, void* arg)
 	/*
 	 * and send TCP-query with found address (local) and client address to dnstap process
 	 */
-	log_addr("query from client", &data->query->addr, data->query->addr.ss_family);
-	log_addr("to server (local)", &data->socket->addr.ai_addr, data->query->addr.ss_family);
-	dt_collector_submit_auth_query(data->nsd, &data->socket->addr.ai_addr, &data->query->addr,
+	log_addr("query from client", &data->query->addr);
+	log_addr("to server (local)", (void*)&data->socket->addr.ai_addr);
+	dt_collector_submit_auth_query(data->nsd, (void*)&data->socket->addr.ai_addr, &data->query->addr,
 		data->query->addrlen, data->query->tcp, data->query->packet);
 #endif /* USE_DNSTAP */
 	data->query_state = server_process_query(data->nsd, data->query);
@@ -3738,9 +3748,9 @@ handle_tcp_reading(int fd, short event, void* arg)
 	/*
 	 * sending TCP-response with found (earlier) address (local) and client address to dnstap process
 	 */
-	log_addr("from server (local)", &data->socket->addr.ai_addr, data->query->addr.ss_family);
-	log_addr("response to client", &data->query->addr, data->query->addr.ss_family);
-	dt_collector_submit_auth_response(data->nsd, &data->socket->addr.ai_addr, &data->query->addr,
+	log_addr("from server (local)", (void*)&data->socket->addr.ai_addr);
+	log_addr("response to client", &data->query->addr);
+	dt_collector_submit_auth_response(data->nsd, (void*)&data->socket->addr.ai_addr, &data->query->addr,
 		data->query->addrlen, data->query->tcp, data->query->packet,
 		data->query->zone);
 #endif /* USE_DNSTAP */
@@ -4173,9 +4183,9 @@ handle_tls_reading(int fd, short event, void* arg)
 	/*
 	 * and send TCP-query with found address (local) and client address to dnstap process
 	 */
-	log_addr("query from client", &data->query->addr, data->query->addr.ss_family);
-	log_addr("to server (local)", &data->socket->addr.ai_addr, data->query->addr.ss_family);
-	dt_collector_submit_auth_query(data->nsd, &data->socket->addr.ai_addr, &data->query->addr,
+	log_addr("query from client", &data->query->addr);
+	log_addr("to server (local)", (void*)&data->socket->addr.ai_addr);
+	dt_collector_submit_auth_query(data->nsd, (void*)&data->socket->addr.ai_addr, &data->query->addr,
 		data->query->addrlen, data->query->tcp, data->query->packet);
 #endif /* USE_DNSTAP */
 	data->query_state = server_process_query(data->nsd, data->query);
@@ -4226,9 +4236,9 @@ handle_tls_reading(int fd, short event, void* arg)
 	/*
 	 * sending TCP-response with found (earlier) address (local) and client address to dnstap process
 	 */
-	log_addr("from server (local)", &data->socket->addr.ai_addr, data->query->addr.ss_family);
-	log_addr("response to client", &data->query->addr, data->query->addr.ss_family);
-	dt_collector_submit_auth_response(data->nsd, &data->socket->addr.ai_addr, &data->query->addr,
+	log_addr("from server (local)", (void*)&data->socket->addr.ai_addr);
+	log_addr("response to client", &data->query->addr);
+	dt_collector_submit_auth_response(data->nsd, (void*)&data->socket->addr.ai_addr, &data->query->addr,
 		data->query->addrlen, data->query->tcp, data->query->packet,
 		data->query->zone);
 #endif /* USE_DNSTAP */
