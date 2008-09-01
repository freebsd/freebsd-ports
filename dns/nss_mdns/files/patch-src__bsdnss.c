--- src/bsdnss.c.orig	2008-04-30 02:40:37.000000000 +0530
+++ src/bsdnss.c	2008-04-30 02:43:11.000000000 +0530
@@ -56,7 +56,7 @@
 #if defined(NSS_IPV4_ONLY) || defined(NSS_IPV6_ONLY)
 /*
  * FreeBSD's libc is always built with IPv4 support.
- * There is no way of telling at compile time with a define if libc
+ * Therxe is no way of telling at compile time with a define if libc
  * was built with -DINET6 or not; a configure test would be required.
  * Therefore, distinguishing between the two makes no sense.
  */
@@ -219,22 +219,8 @@
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
+					    mbuflen, &_errno, &_h_errno);
 	status = __nss_compat_result(status, _errno);
 
 	if (status == NS_SUCCESS) {
