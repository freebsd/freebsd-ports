--- ace/SSL/SSL_Context.cpp.orig	2015-09-17 06:55:18 UTC
+++ ace/SSL/SSL_Context.cpp
@@ -250,6 +250,7 @@ ACE_SSL_Context::set_mode (int mode)
       method = ::SSLv2_method ();
       break;
 #endif /* OPENSSL_NO_SSL2 */
+#if !defined (OPENSSL_NO_SSL3)
     case ACE_SSL_Context::SSLv3_client:
       method = ::SSLv3_client_method ();
       break;
@@ -259,6 +260,7 @@ ACE_SSL_Context::set_mode (int mode)
     case ACE_SSL_Context::SSLv3:
       method = ::SSLv3_method ();
       break;
+#endif /* OPENSSL_NO_SSL3 */
     case ACE_SSL_Context::SSLv23_client:
       method = ::SSLv23_client_method ();
       break;
@@ -300,7 +302,7 @@ ACE_SSL_Context::set_mode (int mode)
       break;
 #endif
     default:
-      method = ::SSLv3_method ();
+      method = ::SSLv23_method ();
       break;
     }
 
@@ -494,8 +496,10 @@ ACE_SSL_Context::load_trusted_ca (const 
       || mode_ == SSLv2
       || mode_ == SSLv2_server
 #endif /* !OPENSSL_NO_SSL2 */
+#if !defined (OPENSSL_NO_SSL3)
       || mode_ == SSLv3
       || mode_ == SSLv3_server)
+#endif /* !OPENSSL_NO_SSL3 */
     {
       // Note: The STACK_OF(X509_NAME) pointer is a copy of the pointer in
       // the CTX; any changes to it by way of these function calls will
@@ -683,7 +687,7 @@ ACE_SSL_Context::random_seed (const char
 int
 ACE_SSL_Context::egd_file (const char * socket_file)
 {
-#if OPENSSL_VERSION_NUMBER < 0x00905100L
+#if OPENSSL_VERSION_NUMBER < 0x00905100L || defined(LIBRESSL_VERSION_NUMBER)
   // OpenSSL < 0.9.5 doesn't have EGD support.
   ACE_UNUSED_ARG (socket_file);
   ACE_NOTSUP_RETURN (-1);
