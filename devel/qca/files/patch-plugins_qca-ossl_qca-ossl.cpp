Patch from OpenBSD rsadowski@ 

LibreSSL 3.0.x support from Stefan Strogin <steils@gentoo.org>

Index: plugins/qca-ossl/qca-ossl.cpp
--- plugins/qca-ossl/qca-ossl.cpp.orig	2021-02-04 10:29:44 UTC
+++ plugins/qca-ossl/qca-ossl.cpp
@@ -41,7 +41,13 @@
 #include <openssl/ssl.h>
 #include <openssl/x509v3.h>
 
+#ifndef RSA_F_RSA_OSSL_PRIVATE_DECRYPT
+#define RSA_F_RSA_OSSL_PRIVATE_DECRYPT RSA_F_RSA_EAY_PRIVATE_DECRYPT
+#endif
+
+#ifndef LIBRESSL_VERSION_NUMBER
 #include <openssl/kdf.h>
+#endif
 
 using namespace QCA;
 
@@ -1239,6 +1245,7 @@ class opensslPbkdf2Context : public KDFContext (public
 protected:
 };
 
+#ifndef LIBRESSL_VERSION_NUMBER
 class opensslHkdfContext : public HKDFContext
 {
     Q_OBJECT
@@ -1271,6 +1278,7 @@ class opensslHkdfContext : public HKDFContext (public)
         return out;
     }
 };
+#endif // LIBRESSL_VERSION_NUMBER
 
 class opensslHMACContext : public MACContext
 {
@@ -4951,7 +4959,11 @@ class MyTLSContext : public TLSContext (public)
         case TLS::TLS_v1:
             ctx = SSL_CTX_new(TLS_client_method());
             SSL_CTX_set_min_proto_version(ctx, TLS1_VERSION);
+#ifdef TLS1_3_VERSION           
             SSL_CTX_set_max_proto_version(ctx, TLS1_3_VERSION);
+#else
+            SSL_CTX_set_max_proto_version(ctx, TLS1_2_VERSION);
+#endif
             break;
         case TLS::DTLS_v1:
         default:
@@ -4972,7 +4984,11 @@ class MyTLSContext : public TLSContext (public)
         QStringList cipherList;
         for (int i = 0; i < sk_SSL_CIPHER_num(sk); ++i) {
             const SSL_CIPHER *thisCipher = sk_SSL_CIPHER_value(sk, i);
+#ifndef LIBRESSL_VERSION_NUMBER
             cipherList += QString::fromLatin1(SSL_CIPHER_standard_name(thisCipher));
+#else
+            cipherList += QString::fromLatin1(SSL_CIPHER_get_name(thisCipher));
+#endif
         }
         sk_SSL_CIPHER_free(sk);
 
@@ -5345,7 +5361,11 @@ class MyTLSContext : public TLSContext (public)
             sessInfo.version = TLS::TLS_v1;
         }
 
+#ifndef LIBRESSL_VERSION_NUMBER
         sessInfo.cipherSuite = QString::fromLatin1(SSL_CIPHER_standard_name(SSL_get_current_cipher(ssl)));
+#else
+        sessInfo.cipherSuite = QString::fromLatin1(SSL_CIPHER_get_name(SSL_get_current_cipher(ssl)));
+#endif
 
         sessInfo.cipherMaxBits = SSL_get_cipher_bits(ssl, &(sessInfo.cipherBits));
 
@@ -6629,7 +6649,9 @@ class opensslProvider : public Provider (public)
 #endif
         list += QStringLiteral("pbkdf1(sha1)");
         list += QStringLiteral("pbkdf2(sha1)");
+#ifndef LIBRESSL_VERSION_NUMBER
         list += QStringLiteral("hkdf(sha256)");
+#endif
         list += QStringLiteral("pkey");
         list += QStringLiteral("dlgroup");
         list += QStringLiteral("rsa");
@@ -6698,8 +6720,10 @@ class opensslProvider : public Provider (public)
 #endif
         else if (type == QLatin1String("pbkdf2(sha1)"))
             return new opensslPbkdf2Context(this, type);
+#ifndef LIBRESSL_VERSION_NUMBER
         else if (type == QLatin1String("hkdf(sha256)"))
             return new opensslHkdfContext(this, type);
+#endif
         else if (type == QLatin1String("hmac(md5)"))
             return new opensslHMACContext(EVP_md5(), this, type);
         else if (type == QLatin1String("hmac(sha1)"))
