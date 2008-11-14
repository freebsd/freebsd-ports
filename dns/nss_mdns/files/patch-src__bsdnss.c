--- src/bsdnss.c.orig	2007-02-08 16:42:23.000000000 +0000
+++ src/bsdnss.c	2008-10-07 23:38:41.000000000 +0100
@@ -45,6 +45,7 @@
 #include <netinet/in.h>
 #include <netdb.h>
 
+#include "nss_gethostname_select.h"
 #include "config.h"
 
 #ifdef MDNS_MINIMAL
@@ -80,37 +81,6 @@
 ns_mtab *nss_module_register(const char *source, unsigned int *mtabsize,
 			     nss_module_unregister_fn *unreg);
 
-extern enum nss_status _nss_mdns_gethostbyname_r (const char *name, struct hostent * result,
-			   char *buffer, size_t buflen, int *errnop,
-			   int *h_errnop);
-
-extern enum nss_status _nss_mdns_gethostbyname2_r (const char *name, int af, struct hostent * result,
-			    char *buffer, size_t buflen, int *errnop,
-			    int *h_errnop);
-extern enum nss_status _nss_mdns_gethostbyaddr_r (struct in_addr * addr, int len, int type,
-			   struct hostent * result, char *buffer,
-			   size_t buflen, int *errnop, int *h_errnop);
-extern enum nss_status _nss_mdns4_gethostbyname_r (const char *name, struct hostent * result,
-			   char *buffer, size_t buflen, int *errnop,
-			   int *h_errnop);
-
-extern enum nss_status _nss_mdns4_gethostbyname2_r (const char *name, int af, struct hostent * result,
-			    char *buffer, size_t buflen, int *errnop,
-			    int *h_errnop);
-extern enum nss_status _nss_mdns4_gethostbyaddr_r (struct in_addr * addr, int len, int type,
-			   struct hostent * result, char *buffer,
-			   size_t buflen, int *errnop, int *h_errnop);
-extern enum nss_status _nss_mdns6_gethostbyname_r (const char *name, struct hostent * result,
-			   char *buffer, size_t buflen, int *errnop,
-			   int *h_errnop);
-
-extern enum nss_status _nss_mdns6_gethostbyname2_r (const char *name, int af, struct hostent * result,
-			    char *buffer, size_t buflen, int *errnop,
-			    int *h_errnop);
-extern enum nss_status _nss_mdns6_gethostbyaddr_r (struct in_addr * addr, int len, int type,
-			   struct hostent * result, char *buffer,
-			   size_t buflen, int *errnop, int *h_errnop);
-
 typedef enum nss_status 	(*_bsd_nsstub_fn_t)(const char *, struct hostent *, char *, size_t, int *, int *);
 
 /* XXX: FreeBSD 5.x is not supported. */
@@ -219,22 +189,8 @@
 	 * 2. Map hostent to addrinfo.
 	 * 3. Hand-off buffer to libc.
 	 */
-	switch (pai->ai_family) {
-	case AF_UNSPEC:
-		status = _nss_mdns_gethostbyname_r(name, hp, buffer, mbuflen,
-						   &_errno, &_h_errno);
-		break;
-	case AF_INET:
-		status = _nss_mdns4_gethostbyname_r(name, hp, buffer, mbuflen,
-						    &_errno, &_h_errno);
-		break;
-	case AF_INET6:
-		status = _nss_mdns6_gethostbyname_r(name, hp, buffer, mbuflen,
-						    &_errno, &_h_errno);
-		break;
-	default:
-		break;
-	}
+	status = _nss_mdns_gethostbyname2_r(name, pai->ai_family, hp, buffer,
+					   mbuflen, &_errno, &_h_errno);
 	status = __nss_compat_result(status, _errno);
 
 	if (status == NS_SUCCESS) {
