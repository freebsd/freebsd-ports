--- sio/SConnect.c.orig	2007-10-27 11:14:05.000000000 -0700
+++ sio/SConnect.c	2008-09-03 08:25:45.000000000 -0700
@@ -154,7 +154,7 @@ _SConnect(const int sfd, const struct so
 		tv.tv_sec = (tv_sec_t) tlen;
 		tv.tv_usec = 0;
 		result = select(sfd + 1, NULL, SELECT_TYPE_ARG234 &ss, SELECT_TYPE_ARG234 &xx, SELECT_TYPE_ARG5 &tv);
-		if (result == 1) {
+		if (result >= 1) {
 			/* ready */
 			break;
 		} else if (result == 0) {
