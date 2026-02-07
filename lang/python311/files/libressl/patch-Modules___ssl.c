--- Modules/_ssl.c.orig	2024-04-02 08:25:04 UTC
+++ Modules/_ssl.c
@@ -4541,7 +4541,7 @@ set_sni_callback(PySSLContext *self, PyObject *arg, vo
     return 0;
 }
 
-#if OPENSSL_VERSION_NUMBER < 0x30300000L
+#if OPENSSL_VERSION_NUMBER < 0x30300000L && !defined(LIBRESSL_VERSION_NUMBER)
 static X509_OBJECT *x509_object_dup(const X509_OBJECT *obj)
 {
     int ok;
