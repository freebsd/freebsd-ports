--- ace/SSL/SSL_Context.cpp.orig	2016-05-02 07:59:38 UTC
+++ ace/SSL/SSL_Context.cpp
@@ -352,7 +352,7 @@ ACE_SSL_Context::filter_versions (const 
 bool
 ACE_SSL_Context::check_host (const ACE_INET_Addr &host, SSL *peerssl)
 {
-#if defined (OPENSSL_VERSION_NUMBER) && (OPENSSL_VERSION_NUMBER >= 0x10002001L)
+#if defined (OPENSSL_VERSION_NUMBER) && (OPENSSL_VERSION_NUMBER >= 0x10002001L) && !defined(LIBRE_VERSION_NUMBER)
 
   this->check_context ();
 
@@ -629,7 +629,7 @@ ACE_SSL_Context::random_seed (const char
 int
 ACE_SSL_Context::egd_file (const char * socket_file)
 {
-#if OPENSSL_VERSION_NUMBER < 0x00905100L
+#if OPENSSL_VERSION_NUMBER < 0x00905100L || defined(LIBRESSL_VERSION_NUMBER)
   // OpenSSL < 0.9.5 doesn't have EGD support.
   ACE_UNUSED_ARG (socket_file);
   ACE_NOTSUP_RETURN (-1);
