--- ace/SSL/SSL_Context.cpp.orig	2015-09-17 06:55:18 UTC
+++ ace/SSL/SSL_Context.cpp
@@ -683,7 +683,7 @@ ACE_SSL_Context::random_seed (const char
 int
 ACE_SSL_Context::egd_file (const char * socket_file)
 {
-#if OPENSSL_VERSION_NUMBER < 0x00905100L
+#if OPENSSL_VERSION_NUMBER < 0x00905100L || defined(LIBRESSL_VERSION_NUMBER)
   // OpenSSL < 0.9.5 doesn't have EGD support.
   ACE_UNUSED_ARG (socket_file);
   ACE_NOTSUP_RETURN (-1);
