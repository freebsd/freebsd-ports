--- pit_server.c	2015-10-20 14:12:13.000000000 +0000
+++ pit_server.c
@@ -171,5 +171,4 @@
    {
 	USAGE;
-	exit;
    }
    /*
@@ -311,6 +310,6 @@
                   "   ai_socktype  = %d (SOCK_STREAM = %d, SOCK_DGRAM = %d)\n"
                   "   ai_protocol  = %d (IPPROTO_TCP = %d, IPPROTO_UDP = %d)\n"
-                  "   ai_addrlen   = %d (sockaddr_in = %lu, "
-                  "sockaddr_in6 = %lu)\n",
+                  "   ai_addrlen   = %d (sockaddr_in = %zu, "
+                  "sockaddr_in6 = %zu)\n",
                   ai->ai_flags,
                   ai->ai_family,
@@ -621,6 +620,6 @@
                         "Sockaddr info for new TCP client:\n"
                         "   sa_family = %d (AF_INET = %d, AF_INET6 = %d)\n"
-                        "   addr len  = %d (sockaddr_in = %lu, "
-                        "sockaddr_in6 = %lu)\n",
+                        "   addr len  = %d (sockaddr_in = %zu, "
+                        "sockaddr_in6 = %zu)\n",
                         sadr->sa_family,
                         AF_INET,
@@ -729,5 +728,5 @@
                ssize_t rBytes = count;
                fprintf( stderr,
-                        "%s: UDP datagram received (%ld bytes).\n",
+                        "%s: UDP datagram received (%zd bytes).\n",
                         pgmName,
                         count );
@@ -746,6 +745,6 @@
                         "Remote client's sockaddr info:\n"
                         "   sa_family = %d (AF_INET = %d, AF_INET6 = %d)\n"
-                        "   addr len  = %d (sockaddr_in = %lu, "
-                        "sockaddr_in6 = %lu)\n",
+                        "   addr len  = %d (sockaddr_in = %zu, "
+                        "sockaddr_in6 = %zu)\n",
                         sadr->sa_family,
                         AF_INET,
