--- lib/netplay/netsocket.cpp.orig	2013-11-24 01:25:10 UTC
+++ lib/netplay/netsocket.cpp
@@ -1399,9 +1399,6 @@ SocketAddress *resolveHost(const char *h
 	hint.ai_family    = AF_UNSPEC;
 	hint.ai_socktype  = SOCK_STREAM;
 	hint.ai_protocol  = 0;
-#ifdef AI_V4MAPPED
-	flags             |= AI_V4MAPPED;
-#endif
 #ifdef AI_ADDRCONFIG
 	flags             |= AI_ADDRCONFIG;
 #endif
