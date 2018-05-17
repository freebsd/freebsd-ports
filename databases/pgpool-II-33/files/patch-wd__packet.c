--- watchdog/wd_packet.c.orig	2018-02-22 00:06:40 UTC
+++ watchdog/wd_packet.c
@@ -1211,7 +1211,7 @@ static void calculate_hmac_sha256(const 
 	unsigned int res_len = WD_AUTH_HASH_LEN;
 	HMAC_CTX *ctx = NULL;
 	
-#if (OPENSSL_VERSION_NUMBER >= 0x10100000L)
+#if (OPENSSL_VERSION_NUMBER >= 0x10100000L) && !defined(LIBRESSL_VERSION_NUMBER)
 	ctx = HMAC_CTX_new();
 	HMAC_CTX_reset(ctx);
 #else
@@ -1222,7 +1222,7 @@ static void calculate_hmac_sha256(const 
 	HMAC_Init_ex(ctx, key, strlen(key), EVP_sha256(), NULL);
 	HMAC_Update(ctx, (unsigned char*)data, len);
 	HMAC_Final(ctx, (unsigned char*)str, &res_len);
-#if (OPENSSL_VERSION_NUMBER >= 0x10100000L)
+#if (OPENSSL_VERSION_NUMBER >= 0x10100000L) && !defined(LIBRESSL_VERSION_NUMBER)
 	HMAC_CTX_reset(ctx);
 	HMAC_CTX_free(ctx);
 #else
