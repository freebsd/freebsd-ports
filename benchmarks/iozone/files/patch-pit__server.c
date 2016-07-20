--- pit_server.c.orig	2015-10-20 14:12:13 UTC
+++ pit_server.c
@@ -170,7 +170,6 @@ int main( int   argc,
    if(need < 1)
    {
 	USAGE;
-	exit;
    }
    /*
    ** Open both a TCP and UDP socket, for both IPv4 & IPv6, on which to receive
@@ -310,8 +309,8 @@ static int openSckt( const char *service
                   "   ai_family    = %d (PF_INET = %d, PF_INET6 = %d)\n"
                   "   ai_socktype  = %d (SOCK_STREAM = %d, SOCK_DGRAM = %d)\n"
                   "   ai_protocol  = %d (IPPROTO_TCP = %d, IPPROTO_UDP = %d)\n"
-                  "   ai_addrlen   = %d (sockaddr_in = %lu, "
-                  "sockaddr_in6 = %lu)\n",
+                  "   ai_addrlen   = %d (sockaddr_in = %zu, "
+                  "sockaddr_in6 = %zu)\n",
                   ai->ai_flags,
                   ai->ai_family,
                   PF_INET,
@@ -620,8 +619,8 @@ static void pit( int    tSckt[ ],
                fprintf( stderr,
                         "Sockaddr info for new TCP client:\n"
                         "   sa_family = %d (AF_INET = %d, AF_INET6 = %d)\n"
-                        "   addr len  = %d (sockaddr_in = %lu, "
-                        "sockaddr_in6 = %lu)\n",
+                        "   addr len  = %d (sockaddr_in = %zu, "
+                        "sockaddr_in6 = %zu)\n",
                         sadr->sa_family,
                         AF_INET,
                         AF_INET6,
@@ -728,7 +727,7 @@ static void pit( int    tSckt[ ],
             {
                ssize_t rBytes = count;
                fprintf( stderr,
-                        "%s: UDP datagram received (%ld bytes).\n",
+                        "%s: UDP datagram received (%zd bytes).\n",
                         pgmName,
                         count );
                while ( count > 0 )
@@ -745,8 +744,8 @@ static void pit( int    tSckt[ ],
                fprintf( stderr,
                         "Remote client's sockaddr info:\n"
                         "   sa_family = %d (AF_INET = %d, AF_INET6 = %d)\n"
-                        "   addr len  = %d (sockaddr_in = %lu, "
-                        "sockaddr_in6 = %lu)\n",
+                        "   addr len  = %d (sockaddr_in = %zu, "
+                        "sockaddr_in6 = %zu)\n",
                         sadr->sa_family,
                         AF_INET,
                         AF_INET6,
