--- lib/netplay/netplay.c.orig	2010-08-12 01:53:49.000000000 +0400
+++ lib/netplay/netplay.c	2010-11-09 03:37:53.000000000 +0300
@@ -1231,9 +1231,6 @@
 	hint.ai_family    = AF_UNSPEC;
 	hint.ai_socktype  = SOCK_STREAM;
 	hint.ai_protocol  = 0;
-#ifdef AI_V4MAPPED
-	flags             |= AI_V4MAPPED;
-#endif
 #ifdef AI_ADDRCONFIG
 	flags             |= AI_ADDRCONFIG;
 #endif
