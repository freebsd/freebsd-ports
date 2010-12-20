--- src/jrd/gds.cpp.orig	Tue Aug 15 22:49:37 2006
+++ src/jrd/gds.cpp	Tue Aug 15 22:50:14 2006
@@ -3734,7 +3734,7 @@
 		Firebird::PathName msgPrefix;
 		if (!fb_utils::readenv(FB_MSG_ENV, msgPrefix))
 		{
-			msgPrefix = prefix;
+			msgPrefix = FB_MSG_PREFIX;
 		}
 		msgPrefix.copyTo(ib_prefix_msg_val, sizeof(ib_prefix_msg_val));
 		ib_prefix_msg = ib_prefix_msg_val;
