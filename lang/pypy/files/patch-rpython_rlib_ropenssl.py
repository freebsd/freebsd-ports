--- rpython/rlib/ropenssl.py.orig	2014-09-20 23:16:07.000000000 +0200
+++ rpython/rlib/ropenssl.py	2015-02-25 12:04:12.242014332 +0100
@@ -194,7 +194,6 @@
 if HAVE_OPENSSL_RAND:
     ssl_external('RAND_add', [rffi.CCHARP, rffi.INT, rffi.DOUBLE], lltype.Void)
     ssl_external('RAND_status', [], rffi.INT)
-    ssl_external('RAND_egd', [rffi.CCHARP], rffi.INT)
 ssl_external('SSL_CTX_new', [SSL_METHOD], SSL_CTX)
 ssl_external('SSL_get_SSL_CTX', [SSL], SSL_CTX)
 ssl_external('TLSv1_method', [], SSL_METHOD)
