--- src/ptclib/pssl.cxx.orig	2013-02-20 02:12:00 UTC
+++ src/ptclib/pssl.cxx
@@ -805,9 +805,12 @@ void PSSLContext::Construct(Method metho
   SSL_METHOD * meth;
 
   switch (method) {
+#ifndef OPENSSL_NO_SSL3
+/* fall through to SSLv23_method if unsupported */
     case SSLv3:
       meth = SSLv3_method();
       break;
+#endif
     case TLSv1:
       meth = TLSv1_method(); 
       break;
