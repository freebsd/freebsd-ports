--- storage/innobase/fsp/fsp0fsp.cc.orig	2020-11-02 10:59:53 UTC
+++ storage/innobase/fsp/fsp0fsp.cc
@@ -1281,7 +1281,7 @@ fsp_header_decode_encryption_info(
 
 	if (elen == MY_AES_BAD_DATA) {
 		my_free(master_key);
-		return(NULL);
+		return(false);
 	}
 
 	/* Check checksum bytes. */
