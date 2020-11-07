--- storage/innobase/fsp/fsp0fsp.cc.orig	2020-04-10 19:45:19 UTC
+++ storage/innobase/fsp/fsp0fsp.cc
@@ -1289,7 +1289,7 @@ fsp_header_decode_encryption_info(
 
 	if (elen == MY_AES_BAD_DATA) {
 		my_free(master_key);
-		return(NULL);
+		return(false);
 	}
 
 	/* Check checksum bytes. */
