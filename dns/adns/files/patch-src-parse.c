--- src/parse.c.orig	Wed Aug 11 18:19:45 2004
+++ src/parse.c	Wed Aug 11 18:20:19 2004
@@ -111,7 +111,7 @@
 }
 
 adns_status adns__parse_domain(adns_state ads, int serv, adns_query qu,
-			       vbuf *vb, adns_queryflags flags,
+			       vbuf *vb, parsedomain_flags flags,
 			       const byte *dgram, int dglen, int *cbyte_io, int max) {
   findlabel_state fls;
   
