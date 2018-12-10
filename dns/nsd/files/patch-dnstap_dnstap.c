--- dnstap/dnstap.c.orig	2018-12-09 20:25:39 UTC
+++ dnstap/dnstap.c
@@ -319,7 +319,7 @@ dt_msg_fill_net(struct dt_msg *dm,
 		*has_port = 1;
 	} else if (ss->ss_family == AF_INET) {
 #else
-	if (ss->ss_family == AF_INET) {
+	if (ss->sin_family == AF_INET) {
 #endif /* INET6 */
 		struct sockaddr_in *s = (struct sockaddr_in *) ss;
 
