--- src/plugins/tls/openssl/qx509_openssl.cpp.orig	2023-09-21 19:24:26 UTC
+++ src/plugins/tls/openssl/qx509_openssl.cpp
@@ -64,7 +64,12 @@ QMultiMap<QByteArray, QString> mapFromX509Name(X509_NA
         unsigned char *data = nullptr;
         int size = q_ASN1_STRING_to_UTF8(&data, q_X509_NAME_ENTRY_get_data(e));
         info.insert(name, QString::fromUtf8((char*)data, size));
-        q_CRYPTO_free(data, nullptr, 0);
+#ifndef LIBRESSL_VERSION_NUMBER
+         q_CRYPTO_free(data, nullptr, 0);
+#else
+         q_CRYPTO_free(data);
+#endif
+
     }
 
     return info;
@@ -75,11 +80,27 @@ QDateTime dateTimeFromASN1(const ASN1_TIME *aTime)
     QDateTime result;
     tm lTime;
 
+#if defined(LIBRESSL_VERSION_NUMBER) && (LIBRESSL_VERSION_NUMBER < 0x3060000fL)
+    const char *data;
+    size_t len;
+    int type;
+
+    data = (const char*)ASN1_STRING_get0_data((const ASN1_STRING *)aTime);
+    len = ASN1_STRING_length(aTime);
+    type = ASN1_STRING_type(aTime);
+
+    if (ASN1_time_parse(data, len, &lTime, type) == type) {
+        QDate resDate(lTime.tm_year + 1900, lTime.tm_mon + 1, lTime.tm_mday);
+        QTime resTime(lTime.tm_hour, lTime.tm_min, lTime.tm_sec);
+        result = QDateTime(resDate, resTime, Qt::UTC);
+    }
+#else
     if (q_ASN1_TIME_to_tm(aTime, &lTime)) {
         QDate resDate(lTime.tm_year + 1900, lTime.tm_mon + 1, lTime.tm_mday);
         QTime resTime(lTime.tm_hour, lTime.tm_min, lTime.tm_sec);
         result = QDateTime(resDate, resTime, QTimeZone::UTC);
     }
+#endif
 
     return result;
 }
@@ -190,7 +211,11 @@ QVariant x509UnknownExtensionToValue(X509_EXTENSION *e
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
@@ -286,7 +311,11 @@ QVariant x509ExtensionToValue(X509_EXTENSION *ext)
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
