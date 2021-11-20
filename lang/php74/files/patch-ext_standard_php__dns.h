--- ext/standard/php_dns.h.orig	2021-10-19 15:18:17 UTC
+++ ext/standard/php_dns.h
@@ -26,6 +26,7 @@
     	((int)dns_search(res, dname, class, type, (char *) answer, anslen, (struct sockaddr *)&from, &fromsize))
 #define php_dns_free_handle(res) \
 		dns_free(res)
+#define php_dns_errno(handle) h_errno
 
 #elif defined(HAVE_RES_NSEARCH)
 #define php_dns_search(res, dname, class, type, answer, anslen) \
@@ -39,11 +40,13 @@
 			res_nclose(res); \
 			php_dns_free_res(res)
 #endif
+#define php_dns_errno(handle) handle->res_h_errno
 
 #elif defined(HAVE_RES_SEARCH)
 #define php_dns_search(res, dname, class, type, answer, anslen) \
 			res_search(dname, class, type, answer, anslen)
 #define php_dns_free_handle(res) /* noop */
+#define php_dns_errno(handle) h_errno
 
 #endif
 
