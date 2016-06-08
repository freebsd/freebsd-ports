--- lib/cpp/src/thrift/transport/TSSLSocket.cpp.orig	2015-09-25 02:24:34 UTC
+++ lib/cpp/src/thrift/transport/TSSLSocket.cpp
@@ -139,8 +139,10 @@ static char uppercase(char c);
 SSLContext::SSLContext(const SSLProtocol& protocol) {
   if (protocol == SSLTLS) {
     ctx_ = SSL_CTX_new(SSLv23_method());
+#ifndef OPENSSL_NO_SSL3
   } else if (protocol == SSLv3) {
     ctx_ = SSL_CTX_new(SSLv3_method());
+#endif
   } else if (protocol == TLSv1_0) {
     ctx_ = SSL_CTX_new(TLSv1_method());
   } else if (protocol == TLSv1_1) {
