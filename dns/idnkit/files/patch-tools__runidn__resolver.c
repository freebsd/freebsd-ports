Index: tools/runidn/resolver.c
--- tools/runidn/resolver.c.orig	2002-11-29 14:26:57 UTC
+++ tools/runidn/resolver.c
@@ -726,7 +726,7 @@ ENTRY(gethostbyname2_r)(const char *name
 
 #ifdef HAVE_GETHOSTBYADDR_R
 int
-ENTRY(gethostbyaddr_r)(GHBA_ADDR_T addr, GHBA_ADDRLEN_T len, int type,
+ENTRY(gethostbyaddr_r)(GHBA_ADDR_T addr, socklen_t len, int type,
 		       struct hostent *result,
 		       char *buffer, size_t buflen,
 		       struct hostent **rp, int *errp)
