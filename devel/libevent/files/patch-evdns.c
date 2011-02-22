--- evdns.c.orig	2011-02-22 09:47:55.243428037 +0100
+++ evdns.c	2011-02-22 09:48:00.454027469 +0100
@@ -158,6 +158,15 @@
 
 #define CLASS_INET     EVDNS_CLASS_INET
 
+#ifdef HAVE_SETFD
+#define FD_CLOSEONEXEC(x) do { \
+	if (fcntl(x, F_SETFD, 1) == -1) \
+		event_warn("fcntl(%d, F_SETFD)", x); \
+	} while (0)
+#else
+#define FD_CLOSEONEXEC(x) (void)0
+#endif
+
 struct request {
 	u8 *request;  /* the dns packet data */
 	unsigned int request_len;
@@ -1099,20 +1108,12 @@
 static u16
 transaction_id_pick(void) {
 	for (;;) {
-		const struct request *req = req_head, *started_at;
 		u16 trans_id = trans_id_function();
 
 		if (trans_id == 0xffff) continue;
-		/* now check to see if that id is already inflight */
-		req = started_at = req_head;
-		if (req) {
-			do {
-				if (req->trans_id == trans_id) break;
-				req = req->next;
-			} while (req != started_at);
-		}
-		/* we didn't find it, so this is a good id */
-		if (req == started_at) return trans_id;
+
+		if (request_find_from_trans_id(trans_id) == NULL)
+			return trans_id;
 	}
 }
 
@@ -2132,7 +2133,8 @@
 
 	ns->socket = socket(PF_INET, SOCK_DGRAM, 0);
 	if (ns->socket < 0) { err = 1; goto out1; }
-        evutil_make_socket_nonblocking(ns->socket);
+	FD_CLOSEONEXEC(ns->socket);
+	evutil_make_socket_nonblocking(ns->socket);
 
 	ns->address = address;
 	ns->port = htons(port);
