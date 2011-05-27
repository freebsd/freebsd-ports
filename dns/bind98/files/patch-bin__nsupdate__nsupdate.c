--- bin/nsupdate/nsupdate.c.orig	2011-01-09 21:32:03.000000000 -0800
+++ bin/nsupdate/nsupdate.c	2011-05-27 14:51:32.000000000 -0700
@@ -695,8 +695,10 @@
 				keyfile, isc_result_totext(result));
 			return;
 		}
-	} else
+	} else {
 		dst_key_attach(dstkey, &sig0key);
+		dst_key_free(&dstkey);
+	}
 }
 
 static void
