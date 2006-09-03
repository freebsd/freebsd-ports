Index: tools/runidn/resolver.c
diff -u -p tools/runidn/resolver.c.orig tools/runidn/resolver.c
--- tools/runidn/resolver.c.orig	Fri Nov 29 23:26:57 2002
+++ tools/runidn/resolver.c	Sun Sep  3 21:20:21 2006
@@ -726,7 +726,7 @@ ENTRY(gethostbyname2_r)(const char *name
 
 #ifdef HAVE_GETHOSTBYADDR_R
 int
-ENTRY(gethostbyaddr_r)(GHBA_ADDR_T addr, GHBA_ADDRLEN_T len, int type,
+ENTRY(gethostbyaddr_r)(GHBA_ADDR_T addr, socklen_t len, int type,
 		       struct hostent *result,
 		       char *buffer, size_t buflen,
 		       struct hostent **rp, int *errp)
