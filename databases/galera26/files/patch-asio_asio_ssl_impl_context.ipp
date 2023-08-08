--- asio/asio/ssl/impl/context.ipp.orig	2023-02-03 12:20:21 UTC
+++ asio/asio/ssl/impl/context.ipp
@@ -87,7 +87,7 @@ context::context(context::method m)
 #endif // (OPENSSL_VERSION_NUMBER >= 0x10100000L) || defined(OPENSSL_NO_SSL2)
 
     // SSL v3.
-#if (OPENSSL_VERSION_NUMBER >= 0x10100000L) && !defined(LIBRESSL_VERSION_NUMBER)
+#if (OPENSSL_VERSION_NUMBER >= 0x10100000L)
   case context::sslv3:
     handle_ = ::SSL_CTX_new(::TLS_method());
     if (handle_)
@@ -132,7 +132,7 @@ context::context(context::method m)
 #endif // defined(OPENSSL_NO_SSL3)
 
     // TLS v1.0.
-#if (OPENSSL_VERSION_NUMBER >= 0x10100000L) && !defined(LIBRESSL_VERSION_NUMBER)
+#if (OPENSSL_VERSION_NUMBER >= 0x10100000L)
   case context::tlsv1:
     handle_ = ::SSL_CTX_new(::TLS_method());
     if (handle_)
@@ -177,7 +177,7 @@ context::context(context::method m)
 #endif // defined(SSL_TXT_TLSV1)
 
     // TLS v1.1.
-#if (OPENSSL_VERSION_NUMBER >= 0x10100000L) && !defined(LIBRESSL_VERSION_NUMBER)
+#if (OPENSSL_VERSION_NUMBER >= 0x10100000L)
   case context::tlsv11:
     handle_ = ::SSL_CTX_new(::TLS_method());
     if (handle_)
@@ -222,7 +222,7 @@ context::context(context::method m)
 #endif // defined(SSL_TXT_TLSV1_1)
 
     // TLS v1.2.
-#if (OPENSSL_VERSION_NUMBER >= 0x10100000L) && !defined(LIBRESSL_VERSION_NUMBER)
+#if (OPENSSL_VERSION_NUMBER >= 0x10100000L)
   case context::tlsv12:
     handle_ = ::SSL_CTX_new(::TLS_method());
     if (handle_)
@@ -267,8 +267,7 @@ context::context(context::method m)
 #endif // defined(SSL_TXT_TLSV1_2)
 
     // TLS v1.3.
-#if (OPENSSL_VERSION_NUMBER >= 0x10101000L) \
-    && !defined(LIBRESSL_VERSION_NUMBER)
+#if (OPENSSL_VERSION_NUMBER >= 0x10101000L)
   case context::tlsv13:
     handle_ = ::SSL_CTX_new(::TLS_method());
     if (handle_)
@@ -294,7 +293,6 @@ context::context(context::method m)
     }
     break;
 #else // (OPENSSL_VERSION_NUMBER >= 0x10101000L)
-      //   && !defined(LIBRESSL_VERSION_NUMBER)
   case context::tlsv13:
   case context::tlsv13_client:
   case context::tlsv13_server:
@@ -302,7 +300,6 @@ context::context(context::method m)
         asio::error::invalid_argument, "context");
     break;
 #endif // (OPENSSL_VERSION_NUMBER >= 0x10101000L)
-       //   && !defined(LIBRESSL_VERSION_NUMBER)
 
     // Any supported SSL/TLS version.
   case context::sslv23:
@@ -316,7 +313,7 @@ context::context(context::method m)
     break;
 
     // Any supported TLS version.
-#if (OPENSSL_VERSION_NUMBER >= 0x10100000L) && !defined(LIBRESSL_VERSION_NUMBER)
+#if (OPENSSL_VERSION_NUMBER >= 0x10100000L)
   case context::tls:
     handle_ = ::SSL_CTX_new(::TLS_method());
     if (handle_)
@@ -386,8 +383,7 @@ context::~context()
 {
   if (handle_)
   {
-#if ((OPENSSL_VERSION_NUMBER >= 0x10100000L) \
-      && !defined(LIBRESSL_VERSION_NUMBER)) \
+#if (OPENSSL_VERSION_NUMBER >= 0x10100000L) \
     || defined(ASIO_USE_WOLFSSL)
     void* cb_userdata = ::SSL_CTX_get_default_passwd_cb_userdata(handle_);
 #else // (OPENSSL_VERSION_NUMBER >= 0x10100000L)
@@ -399,8 +395,7 @@ context::~context()
         static_cast<detail::password_callback_base*>(
             cb_userdata);
       delete callback;
-#if ((OPENSSL_VERSION_NUMBER >= 0x10100000L) \
-      && !defined(LIBRESSL_VERSION_NUMBER)) \
+#if (OPENSSL_VERSION_NUMBER >= 0x10100000L) \
     || defined(ASIO_USE_WOLFSSL)
       ::SSL_CTX_set_default_passwd_cb_userdata(handle_, 0);
 #else // (OPENSSL_VERSION_NUMBER >= 0x10100000L)
@@ -738,8 +733,7 @@ ASIO_SYNC_OP_VOID context::use_certificate_chain(
   bio_cleanup bio = { make_buffer_bio(chain) };
   if (bio.p)
   {
-#if ((OPENSSL_VERSION_NUMBER >= 0x10100000L) \
-      && !defined(LIBRESSL_VERSION_NUMBER)) \
+#if (OPENSSL_VERSION_NUMBER >= 0x10100000L) \
     || defined(ASIO_USE_WOLFSSL)
     pem_password_cb* callback = ::SSL_CTX_get_default_passwd_cb(handle_);
     void* cb_userdata = ::SSL_CTX_get_default_passwd_cb_userdata(handle_);
@@ -767,8 +761,7 @@ ASIO_SYNC_OP_VOID context::use_certificate_chain(
       ASIO_SYNC_OP_VOID_RETURN(ec);
     }
 
-#if ((OPENSSL_VERSION_NUMBER >= 0x10002000L) \
-      && !defined(LIBRESSL_VERSION_NUMBER)) \
+#if (OPENSSL_VERSION_NUMBER >= 0x10002000L) \
     || defined(ASIO_USE_WOLFSSL)
     ::SSL_CTX_clear_chain_certs(handle_);
 #else
@@ -846,8 +839,7 @@ ASIO_SYNC_OP_VOID context::use_private_key(
 {
   ::ERR_clear_error();
 
-#if ((OPENSSL_VERSION_NUMBER >= 0x10100000L) \
-      && !defined(LIBRESSL_VERSION_NUMBER)) \
+#if (OPENSSL_VERSION_NUMBER >= 0x10100000L) \
     || defined(ASIO_USE_WOLFSSL)
     pem_password_cb* callback = ::SSL_CTX_get_default_passwd_cb(handle_);
     void* cb_userdata = ::SSL_CTX_get_default_passwd_cb_userdata(handle_);
@@ -915,8 +907,7 @@ ASIO_SYNC_OP_VOID context::use_rsa_private_key(
 {
   ::ERR_clear_error();
 
-#if ((OPENSSL_VERSION_NUMBER >= 0x10100000L) \
-      && !defined(LIBRESSL_VERSION_NUMBER)) \
+#if (OPENSSL_VERSION_NUMBER >= 0x10100000L) \
     || defined(ASIO_USE_WOLFSSL)
     pem_password_cb* callback = ::SSL_CTX_get_default_passwd_cb(handle_);
     void* cb_userdata = ::SSL_CTX_get_default_passwd_cb_userdata(handle_);
@@ -1156,8 +1147,7 @@ int context::verify_callback_function(int preverified,
 ASIO_SYNC_OP_VOID context::do_set_password_callback(
     detail::password_callback_base* callback, asio::error_code& ec)
 {
-#if ((OPENSSL_VERSION_NUMBER >= 0x10100000L) \
-      && !defined(LIBRESSL_VERSION_NUMBER)) \
+#if (OPENSSL_VERSION_NUMBER >= 0x10100000L) \
     || defined(ASIO_USE_WOLFSSL)
   void* old_callback = ::SSL_CTX_get_default_passwd_cb_userdata(handle_);
   ::SSL_CTX_set_default_passwd_cb_userdata(handle_, callback);
