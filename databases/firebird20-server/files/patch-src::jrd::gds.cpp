--- src/jrd/gds.cpp.orig	Fri May 20 16:14:19 2005
+++ src/jrd/gds.cpp	Fri May 20 16:31:25 2005
@@ -1736,8 +1736,7 @@
 			gds__prefix(ib_prefix_msg, "");
 		}
 		else {
-			strcat(ib_prefix_msg_val, ib_prefix_msg);
-			ib_prefix_msg = ib_prefix_msg_val;
+			strcpy(ib_prefix_msg, "%%DATADIR%%");
 		}
 	}
 	strcat(string, ib_prefix_msg);
