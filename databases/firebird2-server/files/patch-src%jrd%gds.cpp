--- src/jrd/gds.cpp.orig	Mon Nov 22 08:11:11 2004
+++ src/jrd/gds.cpp	Wed Jul 27 13:10:40 2005
@@ -1733,7 +1733,7 @@
 	if (ib_prefix_msg == NULL) {
 		if (!(ib_prefix_msg = getenv(FB_MSG_ENV))) {
 			ib_prefix_msg = ib_prefix_msg_val;
-			gds__prefix(ib_prefix_msg, "");
+			strlcpy(ib_prefix_msg_val, FB_MSG_PREFIX, MAXPATHLEN);
 		}
 		else {
 			strcat(ib_prefix_msg_val, ib_prefix_msg);
