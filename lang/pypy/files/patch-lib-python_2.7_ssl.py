--- lib-python/2.7/ssl.py.orig	2014-09-20 23:16:07.000000000 +0200
+++ lib-python/2.7/ssl.py	2015-02-25 11:53:33.893055482 +0100
@@ -62,7 +62,7 @@
 from _ssl import OPENSSL_VERSION_NUMBER, OPENSSL_VERSION_INFO, OPENSSL_VERSION
 from _ssl import SSLError
 from _ssl import CERT_NONE, CERT_OPTIONAL, CERT_REQUIRED
-from _ssl import RAND_status, RAND_egd, RAND_add
+from _ssl import RAND_status, RAND_add
 from _ssl import \
      SSL_ERROR_ZERO_RETURN, \
      SSL_ERROR_WANT_READ, \
