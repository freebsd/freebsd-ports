--- bin/nsupdate/nsupdate.c.orig	2010-12-08 20:31:30.000000000 -0800
+++ bin/nsupdate/nsupdate.c	2011-05-27 15:21:39.000000000 -0700
@@ -694,8 +694,10 @@
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
