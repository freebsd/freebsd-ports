--- bin/dig/dighost.c.orig	2009-02-24 18:39:21.000000000 -0800
+++ bin/dig/dighost.c	2009-11-07 11:03:16.000000000 -0800
@@ -2604,10 +2604,12 @@
 
 	if (sevent->result == ISC_R_CANCELED) {
 		debug("in cancel handler");
-		isc_socket_detach(&query->sock);
-		sockcount--;
-		INSIST(sockcount >= 0);
-		debug("sockcount=%d", sockcount);
+		if (query->sock != NULL) {
+			isc_socket_detach(&query->sock);
+			sockcount--;
+			INSIST(sockcount >= 0);
+			debug("sockcount=%d", sockcount);
+		}
 		query->waiting_connect = ISC_FALSE;
 		isc_event_free(&event);
 		l = query->lookup;
