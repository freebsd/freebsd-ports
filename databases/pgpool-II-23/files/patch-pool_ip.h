--- pool_ip.h.orig	Fri Feb  2 00:31:59 2007
+++ pool_ip.h	Tue Feb 13 17:22:46 2007
@@ -50,7 +50,9 @@
 				   char *numbits, int family);
 
 /* imported from PostgreSQL getaddrinfo.c */
+#if 0
 extern const char * gai_strerror(int errcode);
+#endif
 
 #ifdef HAVE_IPV6
 extern void promote_v4_to_v6_addr(struct sockaddr_storage * addr);
