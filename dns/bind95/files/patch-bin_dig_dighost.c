--- bin/dig/dighost.c.orig	2009-06-23 20:42:32.000000000 -0700
+++ bin/dig/dighost.c	2009-11-07 11:10:12.000000000 -0800
@@ -2606,10 +2606,12 @@
 
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
