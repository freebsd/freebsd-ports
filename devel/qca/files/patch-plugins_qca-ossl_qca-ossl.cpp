--- plugins/qca-ossl/qca-ossl.cpp.orig	2020-02-25 09:08:01 UTC
+++ plugins/qca-ossl/qca-ossl.cpp
@@ -43,6 +43,10 @@
 
 #include <openssl/kdf.h>
 
+#ifndef RSA_F_RSA_OSSL_PRIVATE_DECRYPT
+#define RSA_F_RSA_OSSL_PRIVATE_DECRYPT RSA_F_RSA_EAY_PRIVATE_DECRYPT
+#endif
+
 using namespace QCA;
 
 namespace opensslQCAPlugin {
@@ -1272,6 +1276,7 @@ class opensslHkdfContext : public HKDFContext (public)
 						 const InitializationVector &info, unsigned int keyLength) override
 	{
 		SecureArray out(keyLength);
+#ifdef EVP_PKEY_HKDF
 		EVP_PKEY_CTX *pctx = EVP_PKEY_CTX_new_id(EVP_PKEY_HKDF, nullptr);
 		EVP_PKEY_derive_init(pctx);
 		EVP_PKEY_CTX_set_hkdf_md(pctx, EVP_sha256());
@@ -1281,6 +1286,36 @@ class opensslHkdfContext : public HKDFContext (public)
 		size_t outlen = out.size();
 		EVP_PKEY_derive(pctx, reinterpret_cast<unsigned char*>(out.data()), &outlen);
 		EVP_PKEY_CTX_free(pctx);
+#else
+		unsigned char prk[EVP_MAX_MD_SIZE];
+		unsigned char *ret;
+		unsigned int prk_len;
+		HMAC(EVP_sha256(), salt.data(), salt.size(), reinterpret_cast<const unsigned char*>(secret.data()), secret.size(), prk, &prk_len);
+		HMAC_CTX hmac;
+		unsigned char prev[EVP_MAX_MD_SIZE];
+		size_t done_len = 0;
+		size_t dig_len = EVP_MD_size(EVP_sha256());
+		size_t n = out.size() / dig_len;
+		if (out.size() % dig_len) ++n;
+		HMAC_CTX_init(&hmac);
+		HMAC_Init_ex(&hmac, prk, prk_len, EVP_sha256(), nullptr);
+		for (unsigned int i = 1; i <= n; ++i) {
+			const unsigned char ctr = i;
+			if (i > 1) {
+				HMAC_Init_ex(&hmac, nullptr, 0, nullptr, nullptr);
+				HMAC_Update(&hmac, prev, dig_len);
+			}
+			HMAC_Update(&hmac, reinterpret_cast<const unsigned char*>(info.data()), info.size());
+			HMAC_Update(&hmac, &ctr, 1);
+			HMAC_Final(&hmac, prev, nullptr);
+			size_t copy_len = (done_len + dig_len > out.size()) ?
+					out.size() - done_len : dig_len;
+			memcpy(reinterpret_cast<unsigned char *>(out.data()) + done_len, prev, copy_len);
+			done_len += copy_len;
+		}
+		HMAC_CTX_cleanup(&hmac);
+		OPENSSL_cleanse(prk, sizeof prk);
+#endif
 		return out;
 	}
 };
