Patch from OpenBSD rsadowski@ 

LibreSSL 3.0.x support from Stefan Strogin <steils@gentoo.org>

Index: plugins/qca-ossl/qca-ossl.cpp
--- plugins/qca-ossl/qca-ossl.cpp.orig	2025-03-09 12:09:03 UTC
+++ plugins/qca-ossl/qca-ossl.cpp
@@ -45,7 +45,13 @@
 #include <openssl/provider.h>
 #endif
 
+#ifndef RSA_F_RSA_OSSL_PRIVATE_DECRYPT
+#define RSA_F_RSA_OSSL_PRIVATE_DECRYPT RSA_F_RSA_EAY_PRIVATE_DECRYPT
+#endif
+
+#ifndef LIBRESSL_VERSION_NUMBER
 #include <openssl/kdf.h>
+#endif
 
 using namespace QCA;
 
@@ -1262,6 +1268,7 @@ class opensslPbkdf2Context : public KDFContext (protec
 protected:
 };
 
+#ifndef LIBRESSL_VERSION_NUMBER
 class opensslHkdfContext : public HKDFContext
 {
     Q_OBJECT
@@ -1294,6 +1301,7 @@ class opensslHkdfContext : public HKDFContext (public)
         return out;
     }
 };
+#endif // LIBRESSL_VERSION_NUMBER
 
 class opensslHMACContext : public MACContext
 {
@@ -5004,7 +5012,11 @@ class MyTLSContext : public TLSContext (public)
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
@@ -5025,7 +5037,11 @@ class MyTLSContext : public TLSContext (public)
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
 
@@ -5398,7 +5414,11 @@ class MyTLSContext : public TLSContext (public)
             sessInfo.version = TLS::TLS_v1;
         }
 
+#ifndef LIBRESSL_VERSION_NUMBER
         sessInfo.cipherSuite = QString::fromLatin1(SSL_CIPHER_standard_name(SSL_get_current_cipher(ssl)));
+#else
+        sessInfo.cipherSuite = QString::fromLatin1(SSL_CIPHER_get_name(SSL_get_current_cipher(ssl)));
+#endif
 
         sessInfo.cipherMaxBits = SSL_get_cipher_bits(ssl, &(sessInfo.cipherBits));
 
@@ -6705,7 +6725,9 @@ class opensslProvider : public Provider (public)
         }
         list += QStringLiteral("pkcs12");
         list += QStringLiteral("pbkdf2(sha1)");
+#ifndef LIBRESSL_VERSION_NUMBER
         list += QStringLiteral("hkdf(sha256)");
+#endif
         list += QStringLiteral("pkey");
         list += QStringLiteral("dlgroup");
         list += QStringLiteral("rsa");
@@ -6755,8 +6777,10 @@ class opensslProvider : public Provider (public)
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
