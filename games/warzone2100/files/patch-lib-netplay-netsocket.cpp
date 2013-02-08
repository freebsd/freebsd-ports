--- lib/netplay/netsocket.cpp.orig	2013-01-15 03:54:07.000000000 +0400
+++ lib/netplay/netsocket.cpp	2013-01-18 19:32:35.110932805 +0400
@@ -1399,9 +1399,6 @@
 	hint.ai_family    = AF_UNSPEC;
 	hint.ai_socktype  = SOCK_STREAM;
 	hint.ai_protocol  = 0;
-#ifdef AI_V4MAPPED
-	flags             |= AI_V4MAPPED;
-#endif
 #ifdef AI_ADDRCONFIG
 	flags             |= AI_ADDRCONFIG;
 #endif
