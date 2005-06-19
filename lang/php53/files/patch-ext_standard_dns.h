--- ext/standard/dns.h.orig	Sun Jun 19 11:57:31 2005
+++ ext/standard/dns.h	Sun Jun 19 12:03:37 2005
@@ -25,6 +25,10 @@
 
 #if HAVE_RES_NMKQUERY && HAVE_RES_NSEND && HAVE_DN_EXPAND && HAVE_DN_SKIPNAME
 #define HAVE_DNS_FUNCS 1
+#define res_ninit 	__res_ninit
+#define res_nmkquery	__res_nmkquery
+#define res_nsend	__res_nsend
+#define res_nclose	__res_nclose
 #endif
 
 PHP_FUNCTION(gethostbyaddr);
