--- dnskey.c.orig	2014-02-11 20:45:11 UTC
+++ dnskey.c
@@ -165,11 +165,17 @@ int dnskey_build_pkey(struct rr_dnskey *rr)
 		if (l < e_bytes) /* public key is too short */
 			goto done;
 
-		rsa->e = BN_bin2bn(pk, e_bytes, NULL);
+		BIGNUM *e = BN_bin2bn(pk, e_bytes, NULL);
 		pk += e_bytes;
 		l -= e_bytes;
+		BIGNUM *n = BN_bin2bn(pk, l, NULL);
 
-		rsa->n = BN_bin2bn(pk, l, NULL);
+#if OPENSSL_VERSION_NUMBER < 0x10100005L
+		rsa->e = e;
+		rsa->n = n;
+#else
+		RSA_set0_key(rsa, n, e, NULL);
+#endif
 
 		pkey = EVP_PKEY_new();
 		if (!pkey)
