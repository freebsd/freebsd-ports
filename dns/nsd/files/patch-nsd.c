--- nsd.c.orig	2021-04-06 11:23:15 UTC
+++ nsd.c
@@ -260,7 +260,6 @@ figure_default_sockets(
 	const char *udp_port, const char *tcp_port,
 	const struct addrinfo *hints)
 {
-	int r;
 	size_t i = 0, n = 1;
 	struct addrinfo ai[2] = { *hints, *hints };
 
@@ -301,6 +300,7 @@ figure_default_sockets(
 		 * automatically mapped to our IPv6 socket.
 		 */
 #ifdef IPV6_V6ONLY
+		int r;
 		struct addrinfo *addrs[2] = { NULL, NULL };
 
 		if((r = getaddrinfo(NULL, udp_port, &ai[0], &addrs[0])) == 0 &&
@@ -551,12 +551,12 @@ print_sockets(
 
 	for(i = 0; i < ifs; i++) {
 		assert(udp[i].servers->size == servercnt);
-		addrport2str(&udp[i].addr.ai_addr, sockbuf, sizeof(sockbuf));
+		addrport2str((void*)&udp[i].addr.ai_addr, sockbuf, sizeof(sockbuf));
 		print_socket_servers(&udp[i], serverbuf, serverbufsz);
 		nsd_bitset_or(servers, servers, udp[i].servers);
 		VERBOSITY(3, (LOG_NOTICE, fmt, sockbuf, "udp", serverbuf));
 		assert(tcp[i].servers->size == servercnt);
-		addrport2str(&tcp[i].addr.ai_addr, sockbuf, sizeof(sockbuf));
+		addrport2str((void*)&tcp[i].addr.ai_addr, sockbuf, sizeof(sockbuf));
 		print_socket_servers(&tcp[i], serverbuf, serverbufsz);
 		nsd_bitset_or(servers, servers, tcp[i].servers);
 		VERBOSITY(3, (LOG_NOTICE, fmt, sockbuf, "tcp", serverbuf));
