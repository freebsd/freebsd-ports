Ticket #12575 fix compilation of software using libressl and boost asio
https://svn.boost.org/trac/boost/ticket/12575

--- boost/asio/ssl/impl/context.ipp.orig	2016-09-21 14:33:21 UTC
+++ boost/asio/ssl/impl/context.ipp
@@ -228,7 +228,7 @@ context::~context()
 {
   if (handle_)
   {
-#if (OPENSSL_VERSION_NUMBER >= 0x10100000L)
+#if (OPENSSL_VERSION_NUMBER >= 0x10100000L) && !defined(LIBRESSL_VERSION_NUMBER)
     void* cb_userdata = ::SSL_CTX_get_default_passwd_cb_userdata(handle_);
 #else // (OPENSSL_VERSION_NUMBER >= 0x10100000L)
     void* cb_userdata = handle_->default_passwd_callback_userdata;
@@ -578,7 +578,7 @@ boost::system::error_code context::use_c
   bio_cleanup bio = { make_buffer_bio(chain) };
   if (bio.p)
   {
-#if (OPENSSL_VERSION_NUMBER >= 0x10100000L)
+#if (OPENSSL_VERSION_NUMBER >= 0x10100000L) && !defined(LIBRESSL_VERSION_NUMBER)
     pem_password_cb* callback = ::SSL_CTX_get_default_passwd_cb(handle_);
     void* cb_userdata = ::SSL_CTX_get_default_passwd_cb_userdata(handle_);
 #else // (OPENSSL_VERSION_NUMBER >= 0x10100000L)
@@ -682,7 +682,7 @@ boost::system::error_code context::use_p
 {
   ::ERR_clear_error();
 
-#if (OPENSSL_VERSION_NUMBER >= 0x10100000L)
+#if (OPENSSL_VERSION_NUMBER >= 0x10100000L) && !defined(LIBRESSL_VERSION_NUMBER)
     pem_password_cb* callback = ::SSL_CTX_get_default_passwd_cb(handle_);
     void* cb_userdata = ::SSL_CTX_get_default_passwd_cb_userdata(handle_);
 #else // (OPENSSL_VERSION_NUMBER >= 0x10100000L)
@@ -749,7 +749,7 @@ boost::system::error_code context::use_r
 {
   ::ERR_clear_error();
 
-#if (OPENSSL_VERSION_NUMBER >= 0x10100000L)
+#if (OPENSSL_VERSION_NUMBER >= 0x10100000L) && !defined(LIBRESSL_VERSION_NUMBER)
     pem_password_cb* callback = ::SSL_CTX_get_default_passwd_cb(handle_);
     void* cb_userdata = ::SSL_CTX_get_default_passwd_cb_userdata(handle_);
 #else // (OPENSSL_VERSION_NUMBER >= 0x10100000L)
@@ -988,7 +988,7 @@ int context::verify_callback_function(in
 boost::system::error_code context::do_set_password_callback(
     detail::password_callback_base* callback, boost::system::error_code& ec)
 {
-#if (OPENSSL_VERSION_NUMBER >= 0x10100000L)
+#if (OPENSSL_VERSION_NUMBER >= 0x10100000L) && !defined(LIBRESSL_VERSION_NUMBER)
   void* old_callback = ::SSL_CTX_get_default_passwd_cb_userdata(handle_);
   ::SSL_CTX_set_default_passwd_cb_userdata(handle_, callback);
 #else // (OPENSSL_VERSION_NUMBER >= 0x10100000L)
