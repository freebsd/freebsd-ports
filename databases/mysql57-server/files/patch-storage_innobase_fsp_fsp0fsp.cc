--- storage/innobase/fsp/fsp0fsp.cc.orig	2021-03-26 06:58:52 UTC
+++ storage/innobase/fsp/fsp0fsp.cc
@@ -1281,7 +1281,7 @@ fsp_header_decode_encryption_info(
 
 	if (elen == MY_AES_BAD_DATA) {
 		my_free(master_key);
-		return(NULL);
+		return(false);
 	}
 
 	/* Check checksum bytes. */
