Use accf_dns's kernel module if available.

--- bin/named/interfacemgr.c.orig	2020-08-06 10:05:20 UTC
+++ bin/named/interfacemgr.c
@@ -521,7 +521,8 @@ ns_interface_accepttcp(ns_interface_t *ifp) {
 	 * If/when there a multiple filters listen to the
 	 * result.
 	 */
-	(void)isc_socket_filter(ifp->tcpsocket, "dataready");
+	if (isc_socket_filter(ifp->tcpsocket, "dnsready") != ISC_R_SUCCESS)
+		(void)isc_socket_filter(ifp->tcpsocket, "dataready");
 
 	result = ns_clientmgr_createclients(ifp->clientmgr, 1, ifp, true);
 	if (result != ISC_R_SUCCESS) {
