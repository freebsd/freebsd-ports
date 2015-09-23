--- boost/asio/ssl/old/detail/openssl_context_service.hpp.orig	2013-05-20 14:32:20.000000000 +0200
+++ boost/asio/ssl/old/detail/openssl_context_service.hpp	2015-09-23 19:56:07.615845025 +0200
@@ -85,6 +85,13 @@ public:
       impl = ::SSL_CTX_new(::SSLv2_server_method());
       break;
 #endif // defined(OPENSSL_NO_SSL2)
+#if defined(OPENSSL_NO_SSL3)
+    case context_base::sslv3:
+    case context_base::sslv3_client:
+    case context_base::sslv3_server:
+      boost::asio::detail::throw_error(boost::asio::error::invalid_argument);
+      break;
+#else // defined(OPENSSL_NO_SSL3)
     case context_base::sslv3:
       impl = ::SSL_CTX_new(::SSLv3_method());
       break;
@@ -94,6 +101,7 @@ public:
     case context_base::sslv3_server:
       impl = ::SSL_CTX_new(::SSLv3_server_method());
       break;
+#endif // defined(OPENSSL_NO_SSL3)
     case context_base::tlsv1:
       impl = ::SSL_CTX_new(::TLSv1_method());
       break;
