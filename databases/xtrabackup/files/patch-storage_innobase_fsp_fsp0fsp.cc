--- storage/innobase/fsp/fsp0fsp.cc.orig	2023-03-14 11:58:56 UTC
+++ storage/innobase/fsp/fsp0fsp.cc
@@ -1293,7 +1293,7 @@ fsp_header_decode_encryption_info(
 
 	if (elen == MY_AES_BAD_DATA) {
 		my_free(master_key);
-		return(NULL);
+		return(false);
 	}
 
 	/* Check checksum bytes. */
