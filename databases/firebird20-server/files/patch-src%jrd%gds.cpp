--- src/jrd/gds.cpp.orig	Mon Jan 23 15:04:44 2006
+++ src/jrd/gds.cpp	Mon Jan 23 15:07:20 2006
@@ -3697,7 +3697,7 @@
 		Firebird::string msgPrefix(getenv(FB_MSG_ENV) ? getenv(FB_MSG_ENV) : "");
 		if (msgPrefix.length() == 0) 
 		{
-			msgPrefix = prefix;
+			msgPrefix = FB_MSG_PREFIX;
 		}
 		copyTo(msgPrefix, ib_prefix_msg_val, sizeof(ib_prefix_msg_val));
 		ib_prefix_msg = ib_prefix_msg_val;
