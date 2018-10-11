This is an extract of upstream commit 
    https://cgit.kde.org/qca.git/commit/?id=d58e20ee652038dc4ec4fe4765dc3639ed735526

--- plugins/qca-ossl/qca-ossl.cpp.orig	2017-02-06 12:29:44 UTC
+++ plugins/qca-ossl/qca-ossl.cpp
@@ -1,6 +1,7 @@
 /*
  * Copyright (C) 2004-2007  Justin Karneges <justin@affinix.com>
  * Copyright (C) 2004-2006  Brad Hards <bradh@frogmouth.net>
+ * Copyright (C) 2017       Fabian Vogt <fabian@ritter-vogt.de>
  *
  * This library is free software; you can redistribute it and/or
  * modify it under the terms of the GNU Lesser General Public
@@ -38,6 +39,10 @@
 #include <openssl/pkcs12.h>
 #include <openssl/ssl.h>
 
+extern "C" {
+#include "libcrypto-compat.h"
+}
+
 #ifndef OSSL_097
 // comment this out if you'd rather use openssl 0.9.6
 #define OSSL_097
@@ -52,6 +57,73 @@
 	((_STACK*) (1 ? p : (type*)0))
 #endif
 
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+    #define OSSL_110
+#endif
+
+// OpenSSL 1.1.0 compatibility macros
+#ifdef OSSL_110
+#define M_ASN1_IA5STRING_new() ASN1_IA5STRING_new()
+#else
+static HMAC_CTX *HMAC_CTX_new() { return new HMAC_CTX(); }
+static void HMAC_CTX_free(HMAC_CTX *x) { free(x); }
+static void EVP_PKEY_up_ref(EVP_PKEY *x) { CRYPTO_add(&x->references, 1, CRYPTO_LOCK_EVP_PKEY); }
+static void X509_up_ref(X509 *x) { CRYPTO_add(&x->references, 1, CRYPTO_LOCK_X509); }
+static void X509_CRL_up_ref(X509_CRL *x) { CRYPTO_add(&x->references, 1, CRYPTO_LOCK_X509_CRL); }
+static DSA *EVP_PKEY_get0_DSA(EVP_PKEY *x) { return x->pkey.dsa; }
+static DH *EVP_PKEY_get0_DH(EVP_PKEY *x) { return x->pkey.dh; }
+static int RSA_meth_set_sign(RSA_METHOD *meth,
+                      int (*sign) (int type, const unsigned char *m,
+                                   unsigned int m_length,
+                                   unsigned char *sigret, unsigned int *siglen,
+                                   const RSA *rsa))
+{
+    meth->rsa_sign = sign;
+    return 1;
+}
+int RSA_meth_set_verify(RSA_METHOD *meth,
+                        int (*verify) (int dtype, const unsigned char *m,
+                                       unsigned int m_length,
+                                       const unsigned char *sigbuf,
+                                       unsigned int siglen, const RSA *rsa))
+{
+    meth->rsa_verify = verify;
+    return 1;
+}
+void X509_REQ_get0_signature(const X509_REQ *req, const ASN1_BIT_STRING **psig,
+                             const X509_ALGOR **palg)
+{
+    if (psig != NULL)
+        *psig = req->signature;
+    if (palg != NULL)
+        *palg = req->sig_alg;
+}
+int X509_REQ_get_signature_nid(const X509_REQ *req)
+{
+    return OBJ_obj2nid(req->sig_alg->algorithm);
+}
+void X509_CRL_get0_signature(const X509_CRL *crl, const ASN1_BIT_STRING **psig,
+                             const X509_ALGOR **palg)
+{
+    if (psig != NULL)
+        *psig = crl->signature;
+    if (palg != NULL)
+        *palg = crl->sig_alg;
+}
+int X509_CRL_get_signature_nid(const X509_CRL *crl)
+{
+    return OBJ_obj2nid(crl->sig_alg->algorithm);
+}
+const ASN1_INTEGER *X509_REVOKED_get0_serialNumber(const X509_REVOKED *x)
+{
+    return x->serialNumber;
+}
+const ASN1_TIME *X509_REVOKED_get0_revocationDate(const X509_REVOKED *x)
+{
+    return x->revocationDate;
+}
+#endif
+
 using namespace QCA;
 
 namespace opensslQCAPlugin {
@@ -93,7 +165,7 @@ static QByteArray bio2ba(BIO *b)
 	return buf;
 }
 
-static BigInteger bn2bi(BIGNUM *n)
+static BigInteger bn2bi(const BIGNUM *n)
 {
 	SecureArray buf(BN_num_bytes(n) + 1);
 	buf[0] = 0; // positive
@@ -109,7 +181,7 @@ static BIGNUM *bi2bn(const BigInteger &n)
 
 // take lowest bytes of BIGNUM to fit
 // pad with high byte zeroes to fit
-static SecureArray bn2fixedbuf(BIGNUM *n, int size)
+static SecureArray bn2fixedbuf(const BIGNUM *n, int size)
 {
 	SecureArray buf(BN_num_bytes(n));
 	BN_bn2bin(n, (unsigned char *)buf.data());
@@ -127,8 +199,16 @@ static SecureArray dsasig_der_to_raw(const SecureArray
 	const unsigned char *inp = (const unsigned char *)in.data();
 	d2i_DSA_SIG(&sig, &inp, in.size());
 
-	SecureArray part_r = bn2fixedbuf(sig->r, 20);
-	SecureArray part_s = bn2fixedbuf(sig->s, 20);
+	const BIGNUM *bnr, *bns;
+
+#ifdef OSSL_110
+	DSA_SIG_get0(sig, &bnr, &bns);
+#else
+	bnr = sig->r; bns = sig->s;
+#endif
+
+	SecureArray part_r = bn2fixedbuf(bnr, 20);
+	SecureArray part_s = bn2fixedbuf(bns, 20);
 	SecureArray result;
 	result.append(part_r);
 	result.append(part_s);
@@ -143,13 +223,21 @@ static SecureArray dsasig_raw_to_der(const SecureArray
 		return SecureArray();
 
 	DSA_SIG *sig = DSA_SIG_new();
-	SecureArray part_r(20);
-	SecureArray part_s(20);
+	SecureArray part_r(20); BIGNUM *bnr;
+	SecureArray part_s(20); BIGNUM *bns;
 	memcpy(part_r.data(), in.data(), 20);
 	memcpy(part_s.data(), in.data() + 20, 20);
-	sig->r = BN_bin2bn((const unsigned char *)part_r.data(), part_r.size(), NULL);
-	sig->s = BN_bin2bn((const unsigned char *)part_s.data(), part_s.size(), NULL);
+	bnr = BN_bin2bn((const unsigned char *)part_r.data(), part_r.size(), NULL);
+	bns = BN_bin2bn((const unsigned char *)part_s.data(), part_s.size(), NULL);
 
+#ifdef OSSL_110
+	if(DSA_SIG_set0(sig, bnr, bns) == 0)
+		return SecureArray();
+	// Not documented what happens in the failure case, free bnr and bns?
+#else
+	sig->r = bnr; sig->s = bns;
+#endif
+
 	int len = i2d_DSA_SIG(sig, NULL);
 	SecureArray result(len);
 	unsigned char *p = (unsigned char *)result.data();
@@ -1004,29 +1092,39 @@ class opensslHashContext : public HashContext (public)
 	opensslHashContext(const EVP_MD *algorithm, Provider *p, const QString &type) : HashContext(p, type)
 	{
 		m_algorithm = algorithm;
-		EVP_DigestInit( &m_context, m_algorithm );
+		m_context = EVP_MD_CTX_new();
+		EVP_DigestInit( m_context, m_algorithm );
 	}
 
+	opensslHashContext(const opensslHashContext &other)
+	    : HashContext(other)
+	{
+		m_algorithm = other.m_algorithm;
+		m_context = EVP_MD_CTX_new();
+		EVP_MD_CTX_copy_ex(m_context, other.m_context);
+	}
+
 	~opensslHashContext()
 	{
-		EVP_MD_CTX_cleanup(&m_context);
+		EVP_MD_CTX_free(m_context);
 	}
 
 	void clear()
 	{
-		EVP_MD_CTX_cleanup(&m_context);
-		EVP_DigestInit( &m_context, m_algorithm );
+		EVP_MD_CTX_free(m_context);
+		m_context = EVP_MD_CTX_new();
+		EVP_DigestInit( m_context, m_algorithm );
 	}
 
 	void update(const MemoryRegion &a)
 	{
-		EVP_DigestUpdate( &m_context, (unsigned char*)a.data(), a.size() );
+		EVP_DigestUpdate( m_context, (unsigned char*)a.data(), a.size() );
 	}
 
 	MemoryRegion final()
 	{
 		SecureArray a( EVP_MD_size( m_algorithm ) );
-		EVP_DigestFinal( &m_context, (unsigned char*)a.data(), 0 );
+		EVP_DigestFinal( m_context, (unsigned char*)a.data(), 0 );
 		return a;
 	}
 
@@ -1037,7 +1135,7 @@ class opensslHashContext : public HashContext (public)
 
 protected:
 	const EVP_MD *m_algorithm;
-	EVP_MD_CTX m_context;
+	EVP_MD_CTX *m_context;
 };
 
 
@@ -1047,9 +1145,23 @@ class opensslPbkdf1Context : public KDFContext (public
 	opensslPbkdf1Context(const EVP_MD *algorithm, Provider *p, const QString &type) : KDFContext(p, type)
 	{
 		m_algorithm = algorithm;
-		EVP_DigestInit( &m_context, m_algorithm );
+		m_context = EVP_MD_CTX_new();
+		EVP_DigestInit( m_context, m_algorithm );
 	}
 
+	opensslPbkdf1Context(const opensslPbkdf1Context &other)
+	    : KDFContext(other)
+	{
+		m_algorithm = other.m_algorithm;
+		m_context = EVP_MD_CTX_new();
+		EVP_MD_CTX_copy(m_context, other.m_context);
+	}
+
+	~opensslPbkdf1Context()
+	{
+		EVP_MD_CTX_free(m_context);
+	}
+
 	Provider::Context *clone() const
 	{
 		return new opensslPbkdf1Context( *this );
@@ -1081,16 +1193,16 @@ class opensslPbkdf1Context : public KDFContext (public
 		  DK = Tc<0..dkLen-1>
 		*/
 		// calculate T_1
-		EVP_DigestUpdate( &m_context, (unsigned char*)secret.data(), secret.size() );
-		EVP_DigestUpdate( &m_context, (unsigned char*)salt.data(), salt.size() );
+		EVP_DigestUpdate( m_context, (unsigned char*)secret.data(), secret.size() );
+		EVP_DigestUpdate( m_context, (unsigned char*)salt.data(), salt.size() );
 		SecureArray a( EVP_MD_size( m_algorithm ) );
-		EVP_DigestFinal( &m_context, (unsigned char*)a.data(), 0 );
+		EVP_DigestFinal( m_context, (unsigned char*)a.data(), 0 );
 
 		// calculate T_2 up to T_c
 		for ( unsigned int i = 2; i <= iterationCount; ++i ) {
-			EVP_DigestInit( &m_context, m_algorithm );
-			EVP_DigestUpdate( &m_context, (unsigned char*)a.data(), a.size() );
-			EVP_DigestFinal( &m_context, (unsigned char*)a.data(), 0 );
+			EVP_DigestInit( m_context, m_algorithm );
+			EVP_DigestUpdate( m_context, (unsigned char*)a.data(), a.size() );
+			EVP_DigestFinal( m_context, (unsigned char*)a.data(), 0 );
 		}
 
 		// shrink a to become DK, of the required length
@@ -1136,19 +1248,19 @@ class opensslPbkdf1Context : public KDFContext (public
 		  DK = Tc<0..dkLen-1>
 		*/
 		// calculate T_1
-		EVP_DigestUpdate( &m_context, (unsigned char*)secret.data(), secret.size() );
-		EVP_DigestUpdate( &m_context, (unsigned char*)salt.data(), salt.size() );
+		EVP_DigestUpdate( m_context, (unsigned char*)secret.data(), secret.size() );
+		EVP_DigestUpdate( m_context, (unsigned char*)salt.data(), salt.size() );
 		SecureArray a( EVP_MD_size( m_algorithm ) );
-		EVP_DigestFinal( &m_context, (unsigned char*)a.data(), 0 );
+		EVP_DigestFinal( m_context, (unsigned char*)a.data(), 0 );
 
 		// calculate T_2 up to T_c
 		*iterationCount = 2 - 1;	// <- Have to remove 1, unless it computes one
 		timer.start();				// ^  time more than the base function
 									// ^  with the same iterationCount
 		while (timer.elapsed() < msecInterval) {
-			EVP_DigestInit( &m_context, m_algorithm );
-			EVP_DigestUpdate( &m_context, (unsigned char*)a.data(), a.size() );
-			EVP_DigestFinal( &m_context, (unsigned char*)a.data(), 0 );
+			EVP_DigestInit( m_context, m_algorithm );
+			EVP_DigestUpdate( m_context, (unsigned char*)a.data(), a.size() );
+			EVP_DigestFinal( m_context, (unsigned char*)a.data(), 0 );
 			++(*iterationCount);
 		}
 
@@ -1163,7 +1275,7 @@ class opensslPbkdf1Context : public KDFContext (public
 
 protected:
 	const EVP_MD *m_algorithm;
-	EVP_MD_CTX m_context;
+	EVP_MD_CTX *m_context;
 };
 
 class opensslPbkdf2Context : public KDFContext
@@ -1231,12 +1343,28 @@ class opensslHMACContext : public MACContext (public)
 	opensslHMACContext(const EVP_MD *algorithm, Provider *p, const QString &type) : MACContext(p, type)
 	{
 		m_algorithm = algorithm;
-		HMAC_CTX_init( &m_context );
+		m_context = HMAC_CTX_new();
+#ifndef OSSL_110
+		HMAC_CTX_init( m_context );
+#endif
 	}
 
+	opensslHMACContext(const opensslHMACContext &other)
+	    : MACContext(other)
+	{
+		m_algorithm = other.m_algorithm;
+		m_context = HMAC_CTX_new();
+		HMAC_CTX_copy(m_context, other.m_context);
+	}
+
+	~opensslHMACContext()
+	{
+		HMAC_CTX_free(m_context);
+	}
+
 	void setup(const SymmetricKey &key)
 	{
-		HMAC_Init_ex( &m_context, key.data(), key.size(), m_algorithm, 0 );
+		HMAC_Init_ex( m_context, key.data(), key.size(), m_algorithm, 0 );
 	}
 
 	KeyLength keyLength() const
@@ -1246,14 +1374,18 @@ class opensslHMACContext : public MACContext (public)
 
 	void update(const MemoryRegion &a)
 	{
-		HMAC_Update( &m_context, (unsigned char *)a.data(), a.size() );
+		HMAC_Update( m_context, (unsigned char *)a.data(), a.size() );
 	}
 
 	void final(MemoryRegion *out)
 	{
 		SecureArray sa( EVP_MD_size( m_algorithm ), 0 );
-		HMAC_Final(&m_context, (unsigned char *)sa.data(), 0 );
-		HMAC_CTX_cleanup(&m_context);
+		HMAC_Final(m_context, (unsigned char *)sa.data(), 0 );
+#ifdef OSSL_110
+		HMAC_CTX_reset(m_context);
+#else
+		HMAC_CTX_cleanup(m_context);
+#endif
 		*out = sa;
 	}
 
@@ -1263,7 +1395,7 @@ class opensslHMACContext : public MACContext (public)
 	}
 
 protected:
-	HMAC_CTX m_context;
+	HMAC_CTX *m_context;
 	const EVP_MD *m_algorithm;
 };
 
@@ -1277,7 +1409,7 @@ class EVPKey
 public:
 	enum State { Idle, SignActive, SignError, VerifyActive, VerifyError };
 	EVP_PKEY *pkey;
-	EVP_MD_CTX mdctx;
+	EVP_MD_CTX *mdctx;
 	State state;
 	bool raw_type;
 	SecureArray raw;
@@ -1287,19 +1419,23 @@ class EVPKey
 		pkey = 0;
 		raw_type = false;
 		state = Idle;
+		mdctx = EVP_MD_CTX_new();
 	}
 
 	EVPKey(const EVPKey &from)
 	{
 		pkey = from.pkey;
-		CRYPTO_add(&pkey->references, 1, CRYPTO_LOCK_EVP_PKEY);
+		EVP_PKEY_up_ref(pkey);
 		raw_type = false;
 		state = Idle;
+		mdctx = EVP_MD_CTX_new();
+		EVP_MD_CTX_copy(mdctx, from.mdctx);
 	}
 
 	~EVPKey()
 	{
 		reset();
+		EVP_MD_CTX_free(mdctx);
 	}
 
 	void reset()
@@ -1322,8 +1458,8 @@ class EVPKey
 		else
 		{
 			raw_type = false;
-			EVP_MD_CTX_init(&mdctx);
-			if(!EVP_SignInit_ex(&mdctx, type, NULL))
+			EVP_MD_CTX_init(mdctx);
+			if(!EVP_SignInit_ex(mdctx, type, NULL))
 				state = SignError;
 		}
 	}
@@ -1339,8 +1475,8 @@ class EVPKey
 		else
 		{
 			raw_type = false;
-			EVP_MD_CTX_init(&mdctx);
-			if(!EVP_VerifyInit_ex(&mdctx, type, NULL))
+			EVP_MD_CTX_init(mdctx);
+			if(!EVP_VerifyInit_ex(mdctx, type, NULL))
 				state = VerifyError;
 		}
 	}
@@ -1352,7 +1488,7 @@ class EVPKey
 			if (raw_type)
 				raw += in;
 			else
-				if(!EVP_SignUpdate(&mdctx, in.data(), (unsigned int)in.size()))
+				if(!EVP_SignUpdate(mdctx, in.data(), (unsigned int)in.size()))
 					state = SignError;
 		}
 		else if(state == VerifyActive)
@@ -1360,7 +1496,7 @@ class EVPKey
 			if (raw_type)
 				raw += in;
 			else
-				if(!EVP_VerifyUpdate(&mdctx, in.data(), (unsigned int)in.size()))
+				if(!EVP_VerifyUpdate(mdctx, in.data(), (unsigned int)in.size()))
 					state = VerifyError;
 		}
 	}
@@ -1373,17 +1509,24 @@ class EVPKey
 			unsigned int len = out.size();
 			if (raw_type)
 			{
-				if (pkey->type == EVP_PKEY_RSA)
+				int type;
+#ifdef OSSL_110
+				type = EVP_PKEY_id(pkey);
+#else
+				type = pkey->type;
+#endif
+				if (type == EVP_PKEY_RSA)
 				{
+					RSA *rsa = EVP_PKEY_get0_RSA(pkey);
 					if(RSA_private_encrypt (raw.size(), (unsigned char *)raw.data(),
-											(unsigned char *)out.data(), pkey->pkey.rsa,
+					                        (unsigned char *)out.data(), rsa,
 											RSA_PKCS1_PADDING) == -1) {
 
 						state = SignError;
 						return SecureArray ();
 					}
 				}
-				else if (pkey->type == EVP_PKEY_DSA)
+				else if (type == EVP_PKEY_DSA)
 				{
 					state = SignError;
 					return SecureArray ();
@@ -1395,7 +1538,7 @@ class EVPKey
 				}
 			}
 			else {
-				if(!EVP_SignFinal(&mdctx, (unsigned char *)out.data(), &len, pkey))
+				if(!EVP_SignFinal(mdctx, (unsigned char *)out.data(), &len, pkey))
 				{
 					state = SignError;
 					return SecureArray();
@@ -1418,16 +1561,24 @@ class EVPKey
 				SecureArray out(EVP_PKEY_size(pkey));
 				int len = 0;
 
-				if (pkey->type == EVP_PKEY_RSA) {
+				int type;
+#ifdef OSSL_110
+				type = EVP_PKEY_type(EVP_PKEY_id(pkey));
+#else
+				type = pkey->type;
+#endif
+
+				if (type == EVP_PKEY_RSA) {
+					RSA *rsa = EVP_PKEY_get0_RSA(pkey);
 					if((len = RSA_public_decrypt (sig.size(), (unsigned char *)sig.data(),
-												  (unsigned char *)out.data (), pkey->pkey.rsa,
+					                                (unsigned char *)out.data (), rsa,
 												  RSA_PKCS1_PADDING)) == -1) {
 
 						state = VerifyError;
 						return false;
 					}
 				}
-				else if (pkey->type == EVP_PKEY_DSA)
+				else if (type == EVP_PKEY_DSA)
 				{
 					state = VerifyError;
 					return false;
@@ -1447,7 +1598,7 @@ class EVPKey
 			}
 			else
 			{
-				if(EVP_VerifyFinal(&mdctx, (unsigned char *)sig.data(), (unsigned int)sig.size(), pkey) != 1)
+				if(EVP_VerifyFinal(mdctx, (unsigned char *)sig.data(), (unsigned int)sig.size(), pkey) != 1)
 				{
 					state = VerifyError;
 					return false;
@@ -1561,9 +1712,11 @@ static bool make_dlgroup(const QByteArray &seed, int b
 		return false;
 	if(ret_counter != counter)
 		return false;
-	params->p = bn2bi(dsa->p);
-	params->q = bn2bi(dsa->q);
-	params->g = bn2bi(dsa->g);
+	const BIGNUM *bnp, *bnq, *bng;
+	DSA_get0_pqg(dsa, &bnp, &bnq, &bng);
+	params->p = bn2bi(bnp);
+	params->q = bn2bi(bnq);
+	params->g = bn2bi(bng);
 	DSA_free(dsa);
 	return true;
 }
@@ -1826,10 +1979,11 @@ class RSAKey : public RSAContext (public)
 			return;
 
 		// extract the public key into DER format
-		int len = i2d_RSAPublicKey(evp.pkey->pkey.rsa, NULL);
+		RSA *rsa_pkey = EVP_PKEY_get0_RSA(evp.pkey);
+		int len = i2d_RSAPublicKey(rsa_pkey, NULL);
 		SecureArray result(len);
 		unsigned char *p = (unsigned char *)result.data();
-		i2d_RSAPublicKey(evp.pkey->pkey.rsa, &p);
+		i2d_RSAPublicKey(rsa_pkey, &p);
 		p = (unsigned char *)result.data();
 
 		// put the DER public key back into openssl
@@ -1852,7 +2006,7 @@ class RSAKey : public RSAContext (public)
 
 	virtual int maximumEncryptSize(EncryptionAlgorithm alg) const
 	{
-		RSA *rsa = evp.pkey->pkey.rsa;
+		RSA *rsa = EVP_PKEY_get0_RSA(evp.pkey);
 		int size = 0;
 		switch(alg)
 		{
@@ -1867,7 +2021,7 @@ class RSAKey : public RSAContext (public)
 
 	virtual SecureArray encrypt(const SecureArray &in, EncryptionAlgorithm alg)
 	{
-		RSA *rsa = evp.pkey->pkey.rsa;
+		RSA *rsa = EVP_PKEY_get0_RSA(evp.pkey);
 		SecureArray buf = in;
 		int max = maximumEncryptSize(alg);
 
@@ -1900,7 +2054,7 @@ class RSAKey : public RSAContext (public)
 
 	virtual bool decrypt(const SecureArray &in, SecureArray *out, EncryptionAlgorithm alg)
 	{
-		RSA *rsa = evp.pkey->pkey.rsa;
+		RSA *rsa = EVP_PKEY_get0_RSA(evp.pkey);
 		SecureArray result(RSA_size(rsa));
 		int pad;
 
@@ -2021,14 +2175,10 @@ class RSAKey : public RSAContext (public)
 		evp.reset();
 
 		RSA *rsa = RSA_new();
-		rsa->n = bi2bn(n);
-		rsa->e = bi2bn(e);
-		rsa->p = bi2bn(p);
-		rsa->q = bi2bn(q);
-		rsa->d = bi2bn(d);
-
-		if(!rsa->n || !rsa->e || !rsa->p || !rsa->q || !rsa->d)
+		if(RSA_set0_key(rsa, bi2bn(n), bi2bn(e), bi2bn(d)) == 0
+		    || RSA_set0_factors(rsa, bi2bn(p), bi2bn(q)) == 0)
 		{
+			// Free BIGNUMS?
 			RSA_free(rsa);
 			return;
 		}
@@ -2036,7 +2186,7 @@ class RSAKey : public RSAContext (public)
 		// When private key has no Public Exponent (e) or Private Exponent (d)
 		// need to disable blinding. Otherwise decryption will be broken.
 		// http://www.mail-archive.com/openssl-users@openssl.org/msg63530.html
-		if(BN_is_zero(rsa->e) || BN_is_zero(rsa->d))
+		if(e == BigInteger(0) || d == BigInteger(0))
 			RSA_blinding_off(rsa);
 
 		evp.pkey = EVP_PKEY_new();
@@ -2049,10 +2199,7 @@ class RSAKey : public RSAContext (public)
 		evp.reset();
 
 		RSA *rsa = RSA_new();
-		rsa->n = bi2bn(n);
-		rsa->e = bi2bn(e);
-
-		if(!rsa->n || !rsa->e)
+		if(RSA_set0_key(rsa, bi2bn(n), bi2bn(e), NULL) == 0)
 		{
 			RSA_free(rsa);
 			return;
@@ -2065,27 +2212,42 @@ class RSAKey : public RSAContext (public)
 
 	virtual BigInteger n() const
 	{
-		return bn2bi(evp.pkey->pkey.rsa->n);
+		RSA *rsa = EVP_PKEY_get0_RSA(evp.pkey);
+		const BIGNUM *bnn;
+		RSA_get0_key(rsa, &bnn, NULL, NULL);
+		return bn2bi(bnn);
 	}
 
 	virtual BigInteger e() const
 	{
-		return bn2bi(evp.pkey->pkey.rsa->e);
+		RSA *rsa = EVP_PKEY_get0_RSA(evp.pkey);
+		const BIGNUM *bne;
+		RSA_get0_key(rsa, NULL, &bne, NULL);
+		return bn2bi(bne);
 	}
 
 	virtual BigInteger p() const
 	{
-		return bn2bi(evp.pkey->pkey.rsa->p);
+		RSA *rsa = EVP_PKEY_get0_RSA(evp.pkey);
+		const BIGNUM *bnp;
+		RSA_get0_factors(rsa, &bnp, NULL);
+		return bn2bi(bnp);
 	}
 
 	virtual BigInteger q() const
 	{
-		return bn2bi(evp.pkey->pkey.rsa->q);
+		RSA *rsa = EVP_PKEY_get0_RSA(evp.pkey);
+		const BIGNUM *bnq;
+		RSA_get0_factors(rsa, NULL, &bnq);
+		return bn2bi(bnq);
 	}
 
 	virtual BigInteger d() const
 	{
-		return bn2bi(evp.pkey->pkey.rsa->d);
+		RSA *rsa = EVP_PKEY_get0_RSA(evp.pkey);
+		const BIGNUM *bnd;
+		RSA_get0_key(rsa, NULL, NULL, &bnd);
+		return bn2bi(bnd);
 	}
 
 private slots:
@@ -2134,10 +2296,12 @@ class DSAKeyMaker : public QThread (public)
 	virtual void run()
 	{
 		DSA *dsa = DSA_new();
-		dsa->p = bi2bn(domain.p());
-		dsa->q = bi2bn(domain.q());
-		dsa->g = bi2bn(domain.g());
-		if(!DSA_generate_key(dsa))
+		BIGNUM *pne = bi2bn(domain.p()),
+		*qne = bi2bn(domain.q()),
+		*gne = bi2bn(domain.g());
+
+		if(!DSA_set0_pqg(dsa, pne, qne, gne)
+		    || !DSA_generate_key(dsa))
 		{
 			DSA_free(dsa);
 			return;
@@ -2212,10 +2376,11 @@ class DSAKey : public DSAContext (public)
 			return;
 
 		// extract the public key into DER format
-		int len = i2d_DSAPublicKey(evp.pkey->pkey.dsa, NULL);
+		DSA *dsa_pkey = EVP_PKEY_get0_DSA(evp.pkey);
+		int len = i2d_DSAPublicKey(dsa_pkey, NULL);
 		SecureArray result(len);
 		unsigned char *p = (unsigned char *)result.data();
-		i2d_DSAPublicKey(evp.pkey->pkey.dsa, &p);
+		i2d_DSAPublicKey(dsa_pkey, &p);
 		p = (unsigned char *)result.data();
 
 		// put the DER public key back into openssl
@@ -2244,7 +2409,7 @@ class DSAKey : public DSAContext (public)
 		else
 			transformsig = false;
 
-		evp.startSign(EVP_dss1());
+		evp.startSign(EVP_sha1());
 	}
 
 	virtual void startVerify(SignatureAlgorithm, SignatureFormat format)
@@ -2255,7 +2420,7 @@ class DSAKey : public DSAContext (public)
 		else
 			transformsig = false;
 
-		evp.startVerify(EVP_dss1());
+		evp.startVerify(EVP_sha1());
 	}
 
 	virtual void update(const MemoryRegion &in)
@@ -2305,13 +2470,14 @@ class DSAKey : public DSAContext (public)
 		evp.reset();
 
 		DSA *dsa = DSA_new();
-		dsa->p = bi2bn(domain.p());
-		dsa->q = bi2bn(domain.q());
-		dsa->g = bi2bn(domain.g());
-		dsa->pub_key = bi2bn(y);
-		dsa->priv_key = bi2bn(x);
+		BIGNUM *bnp = bi2bn(domain.p());
+		BIGNUM *bnq = bi2bn(domain.q());
+		BIGNUM *bng = bi2bn(domain.g());
+		BIGNUM *bnpub_key = bi2bn(y);
+		BIGNUM *bnpriv_key = bi2bn(x);
 
-		if(!dsa->p || !dsa->q || !dsa->g || !dsa->pub_key || !dsa->priv_key)
+		if(!DSA_set0_pqg(dsa, bnp, bnq, bng)
+		    || !DSA_set0_key(dsa, bnpub_key, bnpriv_key))
 		{
 			DSA_free(dsa);
 			return;
@@ -2327,12 +2493,13 @@ class DSAKey : public DSAContext (public)
 		evp.reset();
 
 		DSA *dsa = DSA_new();
-		dsa->p = bi2bn(domain.p());
-		dsa->q = bi2bn(domain.q());
-		dsa->g = bi2bn(domain.g());
-		dsa->pub_key = bi2bn(y);
+		BIGNUM *bnp = bi2bn(domain.p());
+		BIGNUM *bnq = bi2bn(domain.q());
+		BIGNUM *bng = bi2bn(domain.g());
+		BIGNUM *bnpub_key = bi2bn(y);
 
-		if(!dsa->p || !dsa->q || !dsa->g || !dsa->pub_key)
+		if(!DSA_set0_pqg(dsa, bnp, bnq, bng)
+		    || !DSA_set0_key(dsa, bnpub_key, NULL))
 		{
 			DSA_free(dsa);
 			return;
@@ -2345,17 +2512,26 @@ class DSAKey : public DSAContext (public)
 
 	virtual DLGroup domain() const
 	{
-		return DLGroup(bn2bi(evp.pkey->pkey.dsa->p), bn2bi(evp.pkey->pkey.dsa->q), bn2bi(evp.pkey->pkey.dsa->g));
+		DSA *dsa = EVP_PKEY_get0_DSA(evp.pkey);
+		const BIGNUM *bnp, *bnq, *bng;
+		DSA_get0_pqg(dsa, &bnp, &bnq, &bng);
+		return DLGroup(bn2bi(bnp), bn2bi(bnq), bn2bi(bng));
 	}
 
 	virtual BigInteger y() const
 	{
-		return bn2bi(evp.pkey->pkey.dsa->pub_key);
+		DSA *dsa = EVP_PKEY_get0_DSA(evp.pkey);
+		const BIGNUM *bnpub_key;
+		DSA_get0_key(dsa, &bnpub_key, NULL);
+		return bn2bi(bnpub_key);
 	}
 
 	virtual BigInteger x() const
 	{
-		return bn2bi(evp.pkey->pkey.dsa->priv_key);
+		DSA *dsa = EVP_PKEY_get0_DSA(evp.pkey);
+		const BIGNUM *bnpriv_key;
+		DSA_get0_key(dsa, NULL, &bnpriv_key);
+		return bn2bi(bnpriv_key);
 	}
 
 private slots:
@@ -2404,9 +2580,10 @@ class DHKeyMaker : public QThread (public)
 	virtual void run()
 	{
 		DH *dh = DH_new();
-		dh->p = bi2bn(domain.p());
-		dh->g = bi2bn(domain.g());
-		if(!DH_generate_key(dh))
+		BIGNUM *bnp = bi2bn(domain.p());
+		BIGNUM *bng = bi2bn(domain.g());
+		if(!DH_set0_pqg(dh, bnp, NULL, bng)
+		        || !DH_generate_key(dh))
 		{
 			DH_free(dh);
 			return;
@@ -2478,12 +2655,15 @@ class DHKey : public DHContext (public)
 		if(!sec)
 			return;
 
-		DH *orig = evp.pkey->pkey.dh;
+		DH *orig = EVP_PKEY_get0_DH(evp.pkey);
 		DH *dh = DH_new();
-		dh->p = BN_dup(orig->p);
-		dh->g = BN_dup(orig->g);
-		dh->pub_key = BN_dup(orig->pub_key);
+		const BIGNUM *bnp, *bng, *bnpub_key;
+		DH_get0_pqg(orig, &bnp, NULL, &bng);
+		DH_get0_key(orig, &bnpub_key, NULL);
 
+		DH_set0_key(dh, BN_dup(bnpub_key), NULL);
+		DH_set0_pqg(dh, BN_dup(bnp), NULL, BN_dup(bng));
+
 		evp.reset();
 
 		evp.pkey = EVP_PKEY_new();
@@ -2498,10 +2678,13 @@ class DHKey : public DHContext (public)
 
 	virtual SymmetricKey deriveKey(const PKeyBase &theirs)
 	{
-		DH *dh = evp.pkey->pkey.dh;
-		DH *them = static_cast<const DHKey *>(&theirs)->evp.pkey->pkey.dh;
+		DH *dh = EVP_PKEY_get0_DH(evp.pkey);
+		DH *them = EVP_PKEY_get0_DH(static_cast<const DHKey *>(&theirs)->evp.pkey);
+		const BIGNUM *bnpub_key;
+		DH_get0_key(them, &bnpub_key, NULL);
+
 		SecureArray result(DH_size(dh));
-		int ret = DH_compute_key((unsigned char *)result.data(), them->pub_key, dh);
+		int ret = DH_compute_key((unsigned char *)result.data(), bnpub_key, dh);
 		if(ret <= 0)
 			return SymmetricKey();
 		result.resize(ret);
@@ -2531,12 +2714,13 @@ class DHKey : public DHContext (public)
 		evp.reset();
 
 		DH *dh = DH_new();
-		dh->p = bi2bn(domain.p());
-		dh->g = bi2bn(domain.g());
-		dh->pub_key = bi2bn(y);
-		dh->priv_key = bi2bn(x);
+		BIGNUM *bnp = bi2bn(domain.p());
+		BIGNUM *bng = bi2bn(domain.g());
+		BIGNUM *bnpub_key = bi2bn(y);
+		BIGNUM *bnpriv_key = bi2bn(x);
 
-		if(!dh->p || !dh->g || !dh->pub_key || !dh->priv_key)
+		if(!DH_set0_key(dh, bnpub_key, bnpriv_key)
+		    || !DH_set0_pqg(dh, bnp, NULL, bng))
 		{
 			DH_free(dh);
 			return;
@@ -2552,11 +2736,12 @@ class DHKey : public DHContext (public)
 		evp.reset();
 
 		DH *dh = DH_new();
-		dh->p = bi2bn(domain.p());
-		dh->g = bi2bn(domain.g());
-		dh->pub_key = bi2bn(y);
+		BIGNUM *bnp = bi2bn(domain.p());
+		BIGNUM *bng = bi2bn(domain.g());
+		BIGNUM *bnpub_key = bi2bn(y);
 
-		if(!dh->p || !dh->g || !dh->pub_key)
+        if(!DH_set0_key(dh, bnpub_key, NULL)
+                || !DH_set0_pqg(dh, bnp, NULL, bng))
 		{
 			DH_free(dh);
 			return;
@@ -2569,17 +2754,26 @@ class DHKey : public DHContext (public)
 
 	virtual DLGroup domain() const
 	{
-		return DLGroup(bn2bi(evp.pkey->pkey.dh->p), bn2bi(evp.pkey->pkey.dh->g));
+		DH *dh = EVP_PKEY_get0_DH(evp.pkey);
+		const BIGNUM *bnp, *bng;
+		DH_get0_pqg(dh, &bnp, NULL, &bng);
+		return DLGroup(bn2bi(bnp), bn2bi(bng));
 	}
 
 	virtual BigInteger y() const
 	{
-		return bn2bi(evp.pkey->pkey.dh->pub_key);
+		DH *dh = EVP_PKEY_get0_DH(evp.pkey);
+		const BIGNUM *bnpub_key;
+		DH_get0_key(dh, &bnpub_key, NULL);
+		return bn2bi(bnpub_key);
 	}
 
 	virtual BigInteger x() const
 	{
-		return bn2bi(evp.pkey->pkey.dh->priv_key);
+		DH *dh = EVP_PKEY_get0_DH(evp.pkey);
+		const BIGNUM *bnpriv_key;
+		DH_get0_key(dh, NULL, &bnpriv_key);
+		return bn2bi(bnpriv_key);
 	}
 
 private slots:
@@ -2618,10 +2812,14 @@ class QCA_RSA_METHOD (public)
 	{
 		key = _key;
 		RSA_set_method(rsa, rsa_method());
+#ifndef OSSL_110
 		rsa->flags |= RSA_FLAG_SIGN_VER;
+#endif
 		RSA_set_app_data(rsa, this);
-		rsa->n = bi2bn(_key.n());
-		rsa->e = bi2bn(_key.e());
+		BIGNUM *bnn = bi2bn(_key.n());
+		BIGNUM *bne = bi2bn(_key.e());
+
+		RSA_set0_key(rsa, bnn, bne, NULL);
 	}
 
 	RSA_METHOD *rsa_method()
@@ -2630,12 +2828,16 @@ class QCA_RSA_METHOD (public)
 
 		if(!ops)
 		{
-			ops = new RSA_METHOD(*RSA_get_default_method());
-			ops->rsa_priv_enc = 0;//pkcs11_rsa_encrypt;
-			ops->rsa_priv_dec = rsa_priv_dec;
-			ops->rsa_sign = rsa_sign;
-			ops->rsa_verify = 0;//pkcs11_rsa_verify;
-			ops->finish = rsa_finish;
+			ops = RSA_meth_dup(RSA_get_default_method());
+			RSA_meth_set_priv_enc(ops, NULL); //pkcs11_rsa_encrypt
+			RSA_meth_set_priv_dec(ops, rsa_priv_dec); //pkcs11_rsa_encrypt
+#ifdef OSSL_110
+			RSA_meth_set_sign(ops, NULL);
+#else
+			RSA_meth_set_sign(ops, rsa_sign);
+#endif
+			RSA_meth_set_verify(ops, NULL); //pkcs11_rsa_verify
+			RSA_meth_set_finish(ops, rsa_finish);
 		}
 		return ops;
 	}
@@ -2654,7 +2856,11 @@ class QCA_RSA_METHOD (public)
 		}
 		else
 		{
+#if OPENSSL_VERSION_NUMBER > 0x10100000L
+			RSAerr(RSA_F_RSA_OSSL_PRIVATE_DECRYPT, RSA_R_UNKNOWN_PADDING_TYPE);
+#else
 			RSAerr(RSA_F_RSA_EAY_PRIVATE_DECRYPT, RSA_R_UNKNOWN_PADDING_TYPE);
+#endif
 			return -1;
 		}
 
@@ -2675,6 +2881,7 @@ class QCA_RSA_METHOD (public)
 		return -1;
 	}
 
+#ifndef OSSL_110
 	static int rsa_sign(int type, const unsigned char *m, unsigned int m_len, unsigned char *sigret, unsigned int *siglen, const RSA *rsa)
 	{
 		QCA_RSA_METHOD *self = (QCA_RSA_METHOD *)RSA_get_app_data(rsa);
@@ -2691,7 +2898,6 @@ class QCA_RSA_METHOD (public)
 		}
 		else
 		{
-
 			// make X509 packet
 			X509_SIG sig;
 			ASN1_TYPE parameter;
@@ -2765,6 +2971,7 @@ class QCA_RSA_METHOD (public)
 
 		return 1;
 	}
+#endif
 
 	static int rsa_finish(RSA *rsa)
 	{
@@ -2866,21 +3073,22 @@ class MyPKeyContext : public PKeyContext (public)
 	PKeyBase *pkeyToBase(EVP_PKEY *pkey, bool sec) const
 	{
 		PKeyBase *nk = 0;
-		if(pkey->type == EVP_PKEY_RSA)
+		int pkey_type = EVP_PKEY_type(EVP_PKEY_id(pkey));
+		if(pkey_type == EVP_PKEY_RSA)
 		{
 			RSAKey *c = new RSAKey(provider());
 			c->evp.pkey = pkey;
 			c->sec = sec;
 			nk = c;
 		}
-		else if(pkey->type == EVP_PKEY_DSA)
+		else if(pkey_type == EVP_PKEY_DSA)
 		{
 			DSAKey *c = new DSAKey(provider());
 			c->evp.pkey = pkey;
 			c->sec = sec;
 			nk = c;
 		}
-		else if(pkey->type == EVP_PKEY_DH)
+		else if(pkey_type == EVP_PKEY_DH)
 		{
 			DHKey *c = new DHKey(provider());
 			c->evp.pkey = pkey;
@@ -2898,8 +3106,10 @@ class MyPKeyContext : public PKeyContext (public)
 	{
 		EVP_PKEY *pkey = get_pkey();
 
+		int pkey_type = EVP_PKEY_type(EVP_PKEY_id(pkey));
+
 		// OpenSSL does not have DH import/export support
-		if(pkey->type == EVP_PKEY_DH)
+		if(pkey_type == EVP_PKEY_DH)
 			return QByteArray();
 
 		BIO *bo = BIO_new(BIO_s_mem());
@@ -2912,8 +3122,10 @@ class MyPKeyContext : public PKeyContext (public)
 	{
 		EVP_PKEY *pkey = get_pkey();
 
+		int pkey_type = EVP_PKEY_type(EVP_PKEY_id(pkey));
+
 		// OpenSSL does not have DH import/export support
-		if(pkey->type == EVP_PKEY_DH)
+		if(pkey_type == EVP_PKEY_DH)
 			return QString();
 
 		BIO *bo = BIO_new(BIO_s_mem());
@@ -2978,9 +3190,10 @@ class MyPKeyContext : public PKeyContext (public)
 			return SecureArray();
 
 		EVP_PKEY *pkey = get_pkey();
+		int pkey_type = EVP_PKEY_type(EVP_PKEY_id(pkey));
 
 		// OpenSSL does not have DH import/export support
-		if(pkey->type == EVP_PKEY_DH)
+		if(pkey_type == EVP_PKEY_DH)
 			return SecureArray();
 
 		BIO *bo = BIO_new(BIO_s_mem());
@@ -3007,9 +3220,10 @@ class MyPKeyContext : public PKeyContext (public)
 			return QString();
 
 		EVP_PKEY *pkey = get_pkey();
+		int pkey_type = EVP_PKEY_type(EVP_PKEY_id(pkey));
 
 		// OpenSSL does not have DH import/export support
-		if(pkey->type == EVP_PKEY_DH)
+		if(pkey_type == EVP_PKEY_DH)
 			return QString();
 
 		BIO *bo = BIO_new(BIO_s_mem());
@@ -3110,11 +3324,18 @@ class X509Item (public)
 			crl = from.crl;
 
 			if(cert)
-				CRYPTO_add(&cert->references, 1, CRYPTO_LOCK_X509);
+				X509_up_ref(cert);
 			if(req)
+			{
+#ifdef OSSL_110
+				// Not exposed, so copy
+				req = X509_REQ_dup(req);
+#else
 				CRYPTO_add(&req->references, 1, CRYPTO_LOCK_X509_REQ);
+#endif
+			}
 			if(crl)
-				CRYPTO_add(&crl->references, 1, CRYPTO_LOCK_X509_CRL);
+				X509_CRL_up_ref(crl);
 		}
 
 		return *this;
@@ -3220,7 +3441,7 @@ class X509Item (public)
 //
 // This code is mostly taken from OpenSSL v0.9.5a
 // by Eric Young
-QDateTime ASN1_UTCTIME_QDateTime(ASN1_UTCTIME *tm, int *isGmt)
+QDateTime ASN1_UTCTIME_QDateTime(const ASN1_UTCTIME *tm, int *isGmt)
 {
 	QDateTime qdt;
 	char *v;
@@ -3318,7 +3539,7 @@ class MyCertContext : public CertContext (public)
 
 	void fromX509(X509 *x)
 	{
-		CRYPTO_add(&x->references, 1, CRYPTO_LOCK_X509);
+		X509_up_ref(x);
 		item.cert = x;
 		make_props();
 	}
@@ -3349,7 +3570,7 @@ class MyCertContext : public CertContext (public)
 		if(priv.key()->type() == PKey::RSA)
 			md = EVP_sha1();
 		else if(priv.key()->type() == PKey::DSA)
-			md = EVP_dss1();
+			md = EVP_sha1();
 		else
 			return false;
 
@@ -3480,7 +3701,7 @@ class MyCertContext : public CertContext (public)
 
 		const MyCertContext *our_cc = this;
 		X509 *x = our_cc->item.cert;
-		CRYPTO_add(&x->references, 1, CRYPTO_LOCK_X509);
+		X509_up_ref(x);
 		sk_X509_push(untrusted_list, x);
 
 		const MyCertContext *other_cc = static_cast<const MyCertContext *>(other);
@@ -3595,14 +3816,31 @@ class MyCertContext : public CertContext (public)
 				p.policies = get_cert_policies(ex);
 		}
 
-		if (x->signature)
+#if OPENSSL_VERSION_NUMBER >= 0x10002000L
+#ifdef OSSL_110
+		const
+#endif
+		ASN1_BIT_STRING *signature;
+
+		X509_get0_signature(&signature, NULL, x);
+		if(signature)
 		{
+			p.sig = QByteArray(signature->length, 0);
+			for (int i=0; i< signature->length; i++)
+				p.sig[i] = signature->data[i];
+		}
+
+		switch( X509_get_signature_nid(x) )
+#else
+		if(x->signature)
+		{
 			p.sig = QByteArray(x->signature->length, 0);
 			for (int i=0; i< x->signature->length; i++)
 				p.sig[i] = x->signature->data[i];
 		}
 
 		switch( OBJ_obj2nid(x->cert_info->signature->algorithm) )
+#endif
 		{
 		case NID_sha1WithRSAEncryption:
 			p.sigalgo = QCA::EMSA3_SHA1;
@@ -3634,7 +3872,11 @@ class MyCertContext : public CertContext (public)
 			p.sigalgo = QCA::EMSA3_SHA512;
 			break;
 		default:
+#if OPENSSL_VERSION_NUMBER >= 0x10002000L
+			qDebug() << "Unknown signature value: " << X509_get_signature_nid(x);
+#else
 			qDebug() << "Unknown signature value: " << OBJ_obj2nid(x->cert_info->signature->algorithm);
+#endif
 			p.sigalgo = QCA::SignatureUnknown;
 		}
 
@@ -3751,7 +3993,7 @@ class MyCAContext : public CAContext (public)
 		if(privateKey -> key()->type() == PKey::RSA)
 			md = EVP_sha1();
 		else if(privateKey -> key()->type() == PKey::DSA)
-			md = EVP_dss1();
+			md = EVP_sha1();
 		else
 			return 0;
 
@@ -3934,7 +4176,7 @@ class MyCSRContext : public CSRContext (public)
 		if(priv.key()->type() == PKey::RSA)
 			md = EVP_sha1();
 		else if(priv.key()->type() == PKey::DSA)
-			md = EVP_dss1();
+			md = EVP_sha1();
 		else
 			return false;
 
@@ -4095,14 +4337,17 @@ class MyCSRContext : public CSRContext (public)
 
 		sk_X509_EXTENSION_pop_free(exts, X509_EXTENSION_free);
 
-		if (x->signature)
+		const ASN1_BIT_STRING *signature;
+
+		X509_REQ_get0_signature(x, &signature, NULL);
+		if(signature)
 		{
-			p.sig = QByteArray(x->signature->length, 0);
-			for (int i=0; i< x->signature->length; i++)
-				p.sig[i] = x->signature->data[i];
+			p.sig = QByteArray(signature->length, 0);
+			for (int i=0; i< signature->length; i++)
+				p.sig[i] = signature->data[i];
 		}
 
-		switch( OBJ_obj2nid(x->sig_alg->algorithm) )
+		switch( X509_REQ_get_signature_nid(x) )
 		{
 		case NID_sha1WithRSAEncryption:
 			p.sigalgo = QCA::EMSA3_SHA1;
@@ -4122,7 +4367,7 @@ class MyCSRContext : public CSRContext (public)
 			p.sigalgo = QCA::EMSA1_SHA1;
 			break;
 		default:
-			qDebug() << "Unknown signature value: " << OBJ_obj2nid(x->sig_alg->algorithm);
+			qDebug() << "Unknown signature value: " << X509_REQ_get_signature_nid(x);
 			p.sigalgo = QCA::SignatureUnknown;
 		}
 
@@ -4186,7 +4431,7 @@ class MyCRLContext : public CRLContext (public)
 
 	void fromX509(X509_CRL *x)
 	{
-		CRYPTO_add(&x->references, 1, CRYPTO_LOCK_X509_CRL);
+		X509_CRL_up_ref(x);
 		item.crl = x;
 		make_props();
 	}
@@ -4238,8 +4483,8 @@ class MyCRLContext : public CRLContext (public)
 
 		for (int i = 0; i < sk_X509_REVOKED_num(revokeStack); ++i) {
 			X509_REVOKED *rev = sk_X509_REVOKED_value(revokeStack, i);
-			BigInteger serial = bn2bi(ASN1_INTEGER_to_BN(rev->serialNumber, NULL));
-			QDateTime time = ASN1_UTCTIME_QDateTime( rev->revocationDate, NULL);
+			BigInteger serial = bn2bi(ASN1_INTEGER_to_BN(X509_REVOKED_get0_serialNumber(rev), NULL));
+			QDateTime time = ASN1_UTCTIME_QDateTime( X509_REVOKED_get0_revocationDate(rev), NULL);
 			QCA::CRLEntry::Reason reason = QCA::CRLEntry::Unspecified;
 			int pos = X509_REVOKED_get_ext_by_NID(rev, NID_crl_reason, -1);
 			if (pos != -1) {
@@ -4288,13 +4533,18 @@ class MyCRLContext : public CRLContext (public)
 			p.revoked.append(thisEntry);
 		}
 
-		if (x->signature)
+		const ASN1_BIT_STRING *signature;
+
+		X509_CRL_get0_signature(x, &signature, NULL);
+		if(signature)
 		{
-			p.sig = QByteArray(x->signature->length, 0);
-			for (int i=0; i< x->signature->length; i++)
-				p.sig[i] = x->signature->data[i];
+			p.sig = QByteArray(signature->length, 0);
+			for (int i=0; i< signature->length; i++)
+				p.sig[i] = signature->data[i];
 		}
-		switch( OBJ_obj2nid(x->sig_alg->algorithm) )
+
+
+		switch( X509_CRL_get_signature_nid(x) )
 		{
 		case NID_sha1WithRSAEncryption:
 			p.sigalgo = QCA::EMSA3_SHA1;
@@ -4326,7 +4576,7 @@ class MyCRLContext : public CRLContext (public)
 			p.sigalgo = QCA::EMSA3_SHA512;
 			break;
 		default:
-			qWarning() << "Unknown signature value: " << OBJ_obj2nid(x->sig_alg->algorithm);
+			qWarning() << "Unknown signature value: " << X509_CRL_get_signature_nid(x);
 			p.sigalgo = QCA::SignatureUnknown;
 		}
 
@@ -4487,21 +4737,21 @@ Validity MyCertContext::validate(const QList<CertConte
 	{
 		const MyCertContext *cc = static_cast<const MyCertContext *>(trusted[n]);
 		X509 *x = cc->item.cert;
-		CRYPTO_add(&x->references, 1, CRYPTO_LOCK_X509);
+		X509_up_ref(x);
 		sk_X509_push(trusted_list, x);
 	}
 	for(n = 0; n < untrusted.count(); ++n)
 	{
 		const MyCertContext *cc = static_cast<const MyCertContext *>(untrusted[n]);
 		X509 *x = cc->item.cert;
-		CRYPTO_add(&x->references, 1, CRYPTO_LOCK_X509);
+		X509_up_ref(x);
 		sk_X509_push(untrusted_list, x);
 	}
 	for(n = 0; n < crls.count(); ++n)
 	{
 		const MyCRLContext *cc = static_cast<const MyCRLContext *>(crls[n]);
 		X509_CRL *x = cc->item.crl;
-		CRYPTO_add(&x->references, 1, CRYPTO_LOCK_X509_CRL);
+		X509_CRL_up_ref(x);
 		crl_list.append(x);
 	}
 
@@ -4526,7 +4776,7 @@ Validity MyCertContext::validate(const QList<CertConte
 	int ret = X509_verify_cert(ctx);
 	int err = -1;
 	if(!ret)
-		err = ctx->error;
+		err = X509_STORE_CTX_get_error(ctx);
 
 	// cleanup
 	X509_STORE_CTX_free(ctx);
@@ -4560,21 +4810,21 @@ Validity MyCertContext::validate_chain(const QList<Cer
 	{
 		const MyCertContext *cc = static_cast<const MyCertContext *>(trusted[n]);
 		X509 *x = cc->item.cert;
-		CRYPTO_add(&x->references, 1, CRYPTO_LOCK_X509);
+		X509_up_ref(x);
 		sk_X509_push(trusted_list, x);
 	}
 	for(n = 1; n < chain.count(); ++n)
 	{
 		const MyCertContext *cc = static_cast<const MyCertContext *>(chain[n]);
 		X509 *x = cc->item.cert;
-		CRYPTO_add(&x->references, 1, CRYPTO_LOCK_X509);
+		X509_up_ref(x);
 		sk_X509_push(untrusted_list, x);
 	}
 	for(n = 0; n < crls.count(); ++n)
 	{
 		const MyCRLContext *cc = static_cast<const MyCRLContext *>(crls[n]);
 		X509_CRL *x = cc->item.crl;
-		CRYPTO_add(&x->references, 1, CRYPTO_LOCK_X509_CRL);
+		X509_CRL_up_ref(x);
 		crl_list.append(x);
 	}
 
@@ -4599,7 +4849,7 @@ Validity MyCertContext::validate_chain(const QList<Cer
 	int ret = X509_verify_cert(ctx);
 	int err = -1;
 	if(!ret)
-		err = ctx->error;
+		err = X509_STORE_CTX_get_error(ctx);
 
 	// grab the chain, which may not be fully populated
 	STACK_OF(X509) *xchain = X509_STORE_CTX_get_chain(ctx);
@@ -4663,7 +4913,7 @@ class MyPKCS12Context : public PKCS12Context (public)
 			for(int n = 1; n < chain.count(); ++n)
 			{
 				X509 *x = static_cast<const MyCertContext *>(chain[n])->item.cert;
-				CRYPTO_add(&x->references, 1, CRYPTO_LOCK_X509);
+				X509_up_ref(x);
 				sk_X509_push(ca, x);
 			}
 		}
@@ -5398,7 +5648,7 @@ class MyTLSContext : public TLSContext (public)
 		OpenSSL_add_ssl_algorithms();
 		SSL_CTX *ctx = 0;
 		switch (version) {
-#ifndef OPENSSL_NO_SSL2
+#if !defined(OPENSSL_NO_SSL2) && !defined(OSSL_110)
 		case TLS::SSL_v2:
 			ctx = SSL_CTX_new(SSLv2_client_method());
 			break;
@@ -5429,8 +5679,8 @@ class MyTLSContext : public TLSContext (public)
 		STACK_OF(SSL_CIPHER) *sk = SSL_get_ciphers(ssl);
 		QStringList cipherList;
 		for(int i = 0; i < sk_SSL_CIPHER_num(sk); ++i) {
-			SSL_CIPHER *thisCipher = sk_SSL_CIPHER_value(sk, i);
-			cipherList += cipherIDtoString(version, thisCipher->id);
+			const SSL_CIPHER *thisCipher = sk_SSL_CIPHER_value(sk, i);
+			cipherList += cipherIDtoString(version, SSL_CIPHER_get_id(thisCipher));
 		}
 
 		SSL_free(ssl);
@@ -5807,13 +6057,15 @@ class MyTLSContext : public TLSContext (public)
 	{
 		SessionInfo sessInfo;
 
-		sessInfo.isCompressed = (0 != SSL_SESSION_get_compress_id(ssl->session));
+		SSL_SESSION *session = SSL_get0_session(ssl);
+		sessInfo.isCompressed = (0 != SSL_SESSION_get_compress_id(session));
+		int ssl_version = SSL_version(ssl);
 
-		if (ssl->version == TLS1_VERSION)
+		if (ssl_version == TLS1_VERSION)
 			sessInfo.version = TLS::TLS_v1;
-		else if (ssl->version == SSL3_VERSION)
+		else if (ssl_version == SSL3_VERSION)
 			sessInfo.version = TLS::SSL_v3;
-		else if (ssl->version == SSL2_VERSION)
+		else if (ssl_version == SSL2_VERSION)
 			sessInfo.version = TLS::SSL_v2;
 		else {
 			qDebug("unexpected version response");
@@ -5821,7 +6073,7 @@ class MyTLSContext : public TLSContext (public)
 		}
 
 		sessInfo.cipherSuite = cipherIDtoString( sessInfo.version,
-												 SSL_get_current_cipher(ssl)->id);
+		                                         SSL_CIPHER_get_id(SSL_get_current_cipher(ssl)));
 
 		sessInfo.cipherMaxBits = SSL_get_cipher_bits(ssl, &(sessInfo.cipherBits));
 
@@ -6393,7 +6645,7 @@ class MyMessageContext : public MessageContext (public
 			for(int n = 0; n < nonroots.count(); ++n)
 			{
 				X509 *x = static_cast<MyCertContext *>(nonroots[n].context())->item.cert;
-				CRYPTO_add(&x->references, 1, CRYPTO_LOCK_X509);
+				X509_up_ref(x);
 				sk_X509_push(other_certs, x);
 			}
 
@@ -6435,7 +6687,7 @@ class MyMessageContext : public MessageContext (public
 
 			other_certs = sk_X509_new_null();
 			X509 *x = static_cast<MyCertContext *>(target.context())->item.cert;
-			CRYPTO_add(&x->references, 1, CRYPTO_LOCK_X509);
+			X509_up_ref(x);
 			sk_X509_push(other_certs, x);
 
 			bi = BIO_new(BIO_s_mem());
@@ -6498,7 +6750,7 @@ class MyMessageContext : public MessageContext (public
 			for(int n = 0; n < untrusted_list.count(); ++n)
 			{
 				X509 *x = static_cast<MyCertContext *>(untrusted_list[n].context())->item.cert;
-				CRYPTO_add(&x->references, 1, CRYPTO_LOCK_X509);
+				X509_up_ref(x);
 				sk_X509_push(other_certs, x);
 			}
 
@@ -6749,14 +7001,27 @@ class opensslCipherContext : public CipherContext (pub
 	opensslCipherContext(const EVP_CIPHER *algorithm, const int pad, Provider *p, const QString &type) : CipherContext(p, type)
 	{
 		m_cryptoAlgorithm = algorithm;
-		EVP_CIPHER_CTX_init(&m_context);
+		m_context = EVP_CIPHER_CTX_new();
+		EVP_CIPHER_CTX_init(m_context);
 		m_pad = pad;
 		m_type = type;
 	}
 
+	opensslCipherContext(const opensslCipherContext &other)
+	    : CipherContext(other)
+	{
+		m_cryptoAlgorithm = other.m_cryptoAlgorithm;
+		m_context = EVP_CIPHER_CTX_new();
+		EVP_CIPHER_CTX_copy(m_context, other.m_context);
+		m_direction = other.m_direction;
+		m_pad = other.m_pad;
+		m_type = other.m_type;
+	}
+
 	~opensslCipherContext()
 	{
-		EVP_CIPHER_CTX_cleanup(&m_context);
+		EVP_CIPHER_CTX_cleanup(m_context);
+		EVP_CIPHER_CTX_free(m_context);
 	}
 
 	void setup(Direction dir,
@@ -6769,20 +7034,20 @@ class opensslCipherContext : public CipherContext (pub
 			m_cryptoAlgorithm = EVP_des_ede();
 		}
 		if (Encode == m_direction) {
-			EVP_EncryptInit_ex(&m_context, m_cryptoAlgorithm, 0, 0, 0);
-			EVP_CIPHER_CTX_set_key_length(&m_context, key.size());
-			EVP_EncryptInit_ex(&m_context, 0, 0,
+			EVP_EncryptInit_ex(m_context, m_cryptoAlgorithm, 0, 0, 0);
+			EVP_CIPHER_CTX_set_key_length(m_context, key.size());
+			EVP_EncryptInit_ex(m_context, 0, 0,
 							   (const unsigned char*)(key.data()),
 							   (const unsigned char*)(iv.data()));
 		} else {
-			EVP_DecryptInit_ex(&m_context, m_cryptoAlgorithm, 0, 0, 0);
-			EVP_CIPHER_CTX_set_key_length(&m_context, key.size());
-			EVP_DecryptInit_ex(&m_context, 0, 0,
+			EVP_DecryptInit_ex(m_context, m_cryptoAlgorithm, 0, 0, 0);
+			EVP_CIPHER_CTX_set_key_length(m_context, key.size());
+			EVP_DecryptInit_ex(m_context, 0, 0,
 							   (const unsigned char*)(key.data()),
 							   (const unsigned char*)(iv.data()));
 		}
 
-		EVP_CIPHER_CTX_set_padding(&m_context, m_pad);
+		EVP_CIPHER_CTX_set_padding(m_context, m_pad);
 	}
 
 	Provider::Context *clone() const
@@ -6792,7 +7057,7 @@ class opensslCipherContext : public CipherContext (pub
 
 	int blockSize() const
 	{
-		return EVP_CIPHER_CTX_block_size(&m_context);
+		return EVP_CIPHER_CTX_block_size(m_context);
 	}
 
 	bool update(const SecureArray &in, SecureArray *out)
@@ -6805,7 +7070,7 @@ class opensslCipherContext : public CipherContext (pub
 		out->resize(in.size()+blockSize());
 		int resultLength;
 		if (Encode == m_direction) {
-			if (0 == EVP_EncryptUpdate(&m_context,
+			if (0 == EVP_EncryptUpdate(m_context,
 									   (unsigned char*)out->data(),
 									   &resultLength,
 									   (unsigned char*)in.data(),
@@ -6813,7 +7078,7 @@ class opensslCipherContext : public CipherContext (pub
 				return false;
 			}
 		} else {
-			if (0 == EVP_DecryptUpdate(&m_context,
+			if (0 == EVP_DecryptUpdate(m_context,
 									   (unsigned char*)out->data(),
 									   &resultLength,
 									   (unsigned char*)in.data(),
@@ -6830,13 +7095,13 @@ class opensslCipherContext : public CipherContext (pub
 		out->resize(blockSize());
 		int resultLength;
 		if (Encode == m_direction) {
-			if (0 == EVP_EncryptFinal_ex(&m_context,
+			if (0 == EVP_EncryptFinal_ex(m_context,
 										 (unsigned char*)out->data(),
 										 &resultLength)) {
 				return false;
 			}
 		} else {
-			if (0 == EVP_DecryptFinal_ex(&m_context,
+			if (0 == EVP_DecryptFinal_ex(m_context,
 										 (unsigned char*)out->data(),
 										 &resultLength)) {
 				return false;
@@ -6871,7 +7136,7 @@ class opensslCipherContext : public CipherContext (pub
 
 
 protected:
-	EVP_CIPHER_CTX m_context;
+	EVP_CIPHER_CTX *m_context;
 	const EVP_CIPHER *m_cryptoAlgorithm;
 	Direction m_direction;
 	int m_pad;
