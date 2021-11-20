--- ext/standard/dns.c.orig	2021-10-19 10:34:32 UTC
+++ ext/standard/dns.c
@@ -798,6 +798,7 @@ PHP_FUNCTION(dns_get_record)
 	zend_long type_param = PHP_DNS_ANY;
 	zval *authns = NULL, *addtl = NULL;
 	int type_to_fetch;
+	int dns_errno;
 #if defined(HAVE_DNS_SEARCH)
 	struct sockaddr_storage from;
 	uint32_t fromsize = sizeof(from);
@@ -946,8 +947,9 @@ PHP_FUNCTION(dns_get_record)
 			n = php_dns_search(handle, hostname, C_IN, type_to_fetch, answer.qb2, sizeof answer);
 
 			if (n < 0) {
+				dns_errno = php_dns_errno(handle);
 				php_dns_free_handle(handle);
-				switch (h_errno) {
+				switch (dns_errno) {
 					case NO_DATA:
 					case HOST_NOT_FOUND:
 						continue;
