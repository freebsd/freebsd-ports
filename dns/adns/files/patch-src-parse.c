--- src/parse.c.orig	Tue Jan 18 22:48:32 2005
+++ src/parse.c	Tue Jan 18 22:48:56 2005
@@ -113,7 +113,7 @@
 }
 
 adns_status adns__parse_domain(adns_state ads, int serv, adns_query qu,
-			       vbuf *vb, adns_queryflags flags,
+			       vbuf *vb, parsedomain_flags flags,
 			       const byte *dgram, int dglen, int *cbyte_io,
 			       int max) {
   findlabel_state fls;
