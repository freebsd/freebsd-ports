--- ace/SSL/SSL_Context.cpp.orig	2014-12-29 10:41:20 UTC
+++ ace/SSL/SSL_Context.cpp
@@ -274,7 +274,7 @@ ACE_SSL_Context::set_mode (int mode)
     case ACE_SSL_Context::TLSv1:
       method = ::TLSv1_method ();
       break;
-#ifdef TLS1_1_VERSION
+#if defined(TLS1_1_VERSION) && (TLS_MAX_VERSION >= TLS1_1_VERSION)
     case ACE_SSL_Context::TLSv1_1_client:
       method = ::TLSv1_1_client_method ();
       break;
@@ -285,7 +285,7 @@ ACE_SSL_Context::set_mode (int mode)
       method = ::TLSv1_1_method ();
       break;
 #endif
-#ifdef TLS1_2_VERSION
+#if defined(TLS1_2_VERSION) && (TLS_MAX_VERSION >= TLS1_2_VERSION)
     case ACE_SSL_Context::TLSv1_2_client:
       method = ::TLSv1_2_client_method ();
       break;
@@ -556,7 +556,7 @@ ACE_SSL_Context::random_seed (const char
 int
 ACE_SSL_Context::egd_file (const char * socket_file)
 {
-#if OPENSSL_VERSION_NUMBER < 0x00905100L
+#if OPENSSL_VERSION_NUMBER < 0x00905100L || defined(LIBRESSL_VERSION_NUMBER)
   // OpenSSL < 0.9.5 doesn't have EGD support.
   ACE_UNUSED_ARG (socket_file);
   ACE_NOTSUP_RETURN (-1);
