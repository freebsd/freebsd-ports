--- mget.c.orig	Sat Sep 22 00:34:44 2001
+++ mget.c	Sat Sep 22 00:35:26 2001
@@ -604,8 +604,10 @@
 	return segment;
 }
 
+/*
 #if !defined(linux) || !defined(HAVE_IPV6)
 char *inet_ntop(int af, INADDR *src, char *dst, size_t cnt){
 	        return inet_ntoa((INADDR)(*src));
 }
 #endif
+*/
