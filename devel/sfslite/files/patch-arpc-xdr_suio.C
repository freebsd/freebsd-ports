--- arpc/xdr_suio.C.orig	2005-11-01 16:20:27.000000000 +0000
+++ arpc/xdr_suio.C	2007-07-12 22:38:45.000000000 +0000
@@ -66,7 +66,7 @@
 };
 static const XDR xsproto = {
   XDR_ENCODE,
-  (xdr_ops_t *) &xsops,
+  (xdr_ops_t *) ((void *)&xsops),
   NULL, NULL, NULL, 0
 };
 
@@ -82,7 +82,7 @@
 };
 static const XDR xsproto_scrub = {
   XDR_ENCODE,
-  (xdr_ops_t *) &xsops_scrub,
+  (xdr_ops_t *) ((void *)&xsops_scrub),
   NULL, NULL, NULL, 0
 };
 
