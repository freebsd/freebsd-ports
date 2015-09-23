--- boost/asio/ssl/impl/context.ipp.orig	2013-10-27 01:25:53.000000000 +0200
+++ boost/asio/ssl/impl/context.ipp	2015-09-23 19:57:24.408873673 +0200
@@ -87,6 +87,14 @@ context::context(context::method m)
     handle_ = ::SSL_CTX_new(::SSLv2_server_method());
     break;
 #endif // defined(OPENSSL_NO_SSL2)
+#if defined(OPENSSL_NO_SSL3)
+  case context::sslv3:
+  case context::sslv3_client:
+  case context::sslv3_server:
+    boost::asio::detail::throw_error(
+        boost::asio::error::invalid_argument, "context");
+    break;
+#else // defined(OPENSSL_NO_SSL3)
   case context::sslv3:
     handle_ = ::SSL_CTX_new(::SSLv3_method());
     break;
@@ -96,6 +104,7 @@ context::context(context::method m)
   case context::sslv3_server:
     handle_ = ::SSL_CTX_new(::SSLv3_server_method());
     break;
+#endif // defined(OPENSSL_NO_SSL3)
   case context::tlsv1:
     handle_ = ::SSL_CTX_new(::TLSv1_method());
     break;
