<<<<<<< HEAD
--- ace/SSL/SSL_Context.cpp.orig	2014-12-29 11:41:20.110460000 +0100
+++ ace/SSL/SSL_Context.cpp	2015-10-04 11:44:07.708381005 +0200
@@ -168,7 +168,7 @@ ACE_SSL_Context::ssl_library_init (void)
       ::RAND_screen ();
 #endif  /* WIN32 */
 
-#if OPENSSL_VERSION_NUMBER >= 0x00905100L
+#if OPENSSL_VERSION_NUMBER >= 0x00905100L && !defined (OPENSSL_NO_EGD)
       // OpenSSL < 0.9.5 doesn't have EGD support.
 
       const char *egd_socket_file =
@@ -247,6 +247,7 @@ ACE_SSL_Context::set_mode (int mode)
       method = ::SSLv2_method ();
       break;
 #endif /* OPENSSL_NO_SSL2 */
+#if !defined (OPENSSL_NO_SSL3)
     case ACE_SSL_Context::SSLv3_client:
       method = ::SSLv3_client_method ();
       break;
@@ -256,6 +257,7 @@ ACE_SSL_Context::set_mode (int mode)
     case ACE_SSL_Context::SSLv3:
       method = ::SSLv3_method ();
       break;
+#endif /* OPENSSL_NO_SSL3 */
     case ACE_SSL_Context::SSLv23_client:
       method = ::SSLv23_client_method ();
       break;
@@ -274,7 +276,7 @@ ACE_SSL_Context::set_mode (int mode)
     case ACE_SSL_Context::TLSv1:
       method = ::TLSv1_method ();
       break;
-#ifdef TLS1_1_VERSION
+#if defined(TLS1_1_VERSION) && (TLS_MAX_VERSION >= TLS1_1_VERSION)
     case ACE_SSL_Context::TLSv1_1_client:
       method = ::TLSv1_1_client_method ();
       break;
@@ -285,7 +287,7 @@ ACE_SSL_Context::set_mode (int mode)
       method = ::TLSv1_1_method ();
       break;
 #endif
-#ifdef TLS1_2_VERSION
+#if defined(TLS1_2_VERSION) && (TLS_MAX_VERSION >= TLS1_2_VERSION)
     case ACE_SSL_Context::TLSv1_2_client:
       method = ::TLSv1_2_client_method ();
       break;
@@ -297,7 +299,7 @@ ACE_SSL_Context::set_mode (int mode)
       break;
 #endif
     default:
-      method = ::SSLv3_method ();
+      method = ::SSLv23_method ();
       break;
     }
 
@@ -367,8 +369,11 @@ ACE_SSL_Context::load_trusted_ca (const 
       || mode_ == SSLv2
       || mode_ == SSLv2_server
 #endif /* !OPENSSL_NO_SSL2 */
+#if !defined (OPENSSL_NO_SSL3)
       || mode_ == SSLv3
-      || mode_ == SSLv3_server)
+      || mode_ == SSLv3_server
+#endif /* !OPENSSL_NO_SSL3 */
+     )
     {
       // Note: The STACK_OF(X509_NAME) pointer is a copy of the pointer in
       // the CTX; any changes to it by way of these function calls will
@@ -556,7 +561,7 @@ ACE_SSL_Context::random_seed (const char
=======
--- ace/SSL/SSL_Context.cpp.orig	2015-09-17 06:55:18 UTC
+++ ace/SSL/SSL_Context.cpp
@@ -683,7 +683,7 @@ ACE_SSL_Context::random_seed (const char
>>>>>>> refs/remotes/pcbsd/master
 int
 ACE_SSL_Context::egd_file (const char * socket_file)
 {
-#if OPENSSL_VERSION_NUMBER < 0x00905100L
+#if OPENSSL_VERSION_NUMBER < 0x00905100L || defined (OPENSSL_NO_EGD)
   // OpenSSL < 0.9.5 doesn't have EGD support.
   ACE_UNUSED_ARG (socket_file);
   ACE_NOTSUP_RETURN (-1);
