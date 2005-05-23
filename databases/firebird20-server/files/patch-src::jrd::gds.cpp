--- src/jrd/gds.cpp.orig	Sun May 22 18:52:41 2005
+++ src/jrd/gds.cpp	Sun May 22 18:55:44 2005
@@ -1732,8 +1732,8 @@
 
 	if (ib_prefix_msg == NULL) {
 		if (!(ib_prefix_msg = getenv(FB_MSG_ENV))) {
+			strncpy(ib_prefix_msg_val, "%%LIBDATADIR%%", MAXPATHLEN);
 			ib_prefix_msg = ib_prefix_msg_val;
-			gds__prefix(ib_prefix_msg, "");
 		}
 		else {
 			strcat(ib_prefix_msg_val, ib_prefix_msg);
