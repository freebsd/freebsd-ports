--- ./libs/l_net/l_net.c.orig	Fri Feb 10 19:01:20 2006
+++ ./libs/l_net/l_net.c	Thu Mar 16 16:37:04 2006
@@ -84,8 +84,7 @@
 {
 #ifdef WIN32
 	return stricmp(addr1->ip, addr2->ip);
-#endif
-#ifdef __linux__
+#else
 	return strcasecmp(addr1->ip, addr2->ip);
 #endif
 } //end of the function Net_AddressCompare
