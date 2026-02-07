Fix compilation with LibreSSL

Index: plugins/qca-ossl/qca-ossl.cpp
--- plugins/qca-ossl/qca-ossl.cpp.orig
+++ plugins/qca-ossl/qca-ossl.cpp
@@ -45,6 +45,11 @@
 #include <openssl/provider.h>
 #endif
 
+#ifndef RSA_F_RSA_OSSL_PRIVATE_DECRYPT
+#define RSA_F_RSA_OSSL_PRIVATE_DECRYPT RSA_F_RSA_EAY_PRIVATE_DECRYPT
+#define SSL_CIPHER_standard_name SSL_CIPHER_get_name
+#endif
+
 #include <openssl/kdf.h>
 
 using namespace QCA;
@@ -6460,7 +6465,7 @@ static QStringList all_hash_types()
         list += QStringLiteral("md2");
 #endif
         list += QStringLiteral("md4");
-#ifdef OBJ_whirlpool
+#ifndef OPENSSL_NO_WHIRLPOOL
         list += QStringLiteral("whirlpool");
 #endif
     }
@@ -6921,7 +6926,7 @@ class opensslProvider : public Provider (public)
 #endif
             else if (type == QLatin1String("md4"))
                 return new opensslHashContext(EVP_md4(), this, type);
-#ifdef OBJ_whirlpool
+#ifndef OPENSSL_NO_WHIRLPOOL
             else if (type == QLatin1String("whirlpool"))
                 return new opensslHashContext(EVP_whirlpool(), this, type);
 #endif
