--- ace/SSL/SSL_Context.cpp.orig	2018-09-18 07:26:56 UTC
+++ ace/SSL/SSL_Context.cpp
@@ -179,7 +179,7 @@ ACE_SSL_Context::ssl_library_init (void)
 # endif  /* OPENSSL_VERSION_NUMBER < 0x10100000L */
 #endif  /* WIN32 */
 
-#if OPENSSL_VERSION_NUMBER >= 0x00905100L
+#if OPENSSL_VERSION_NUMBER < 0x00905100L || defined(LIBRESSL_VERSION_NUMBER)
       // OpenSSL < 0.9.5 doesn't have EGD support.
 
       const char *egd_socket_file =
