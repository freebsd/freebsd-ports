--- src/plugins/tls/openssl/qx509_openssl.cpp.orig	2025-05-14 09:43:58 UTC
+++ src/plugins/tls/openssl/qx509_openssl.cpp
@@ -191,7 +191,11 @@ QVariant x509UnknownExtensionToValue(X509_EXTENSION *e
         QVariantList list;
         bool isMap = false;
 
+#ifdef LIBRESSL_VERSION_NUMBER
+        for (int j = 0; j < q_SKM_sk_num(CONF_VALUE, val); j++) {
+#else
         for (int j = 0; j < q_SKM_sk_num(val); j++) {
+#endif
             CONF_VALUE *nval = q_SKM_sk_value(CONF_VALUE, val, j);
             if (nval->name && nval->value) {
                 isMap = true;
@@ -287,7 +291,11 @@ QVariant x509ExtensionToValue(X509_EXTENSION *ext)
             if (!info)
                 return {};
             QVariantMap result;
+#if defined LIBRESSL_VERSION_NUMBER
+            for (int i=0; i < q_SKM_sk_num(ACCESS_DESCRIPTION, info); i++) {
+#else
             for (int i=0; i < q_SKM_sk_num(info); i++) {
+#endif
                 ACCESS_DESCRIPTION *ad = q_SKM_sk_value(ACCESS_DESCRIPTION, info, i);
 
                 GENERAL_NAME *name = ad->location;
