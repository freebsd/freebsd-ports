--- src/edns0.c.orig	2017-05-12 14:16:02 UTC
+++ src/edns0.c
@@ -304,7 +304,7 @@ static size_t calc_subnet_opt(struct sub
   /* http://tools.ietf.org/html/draft-vandergaast-edns-client-subnet-02 */
   
   int len;
-  void *addrp;
+  void *addrp = NULL;
   int sa_family = source->sa.sa_family;
 
   opt->source_netmask = 0;
