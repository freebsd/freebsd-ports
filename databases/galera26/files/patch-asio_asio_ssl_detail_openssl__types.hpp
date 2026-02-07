--- asio/asio/ssl/detail/openssl_types.hpp.orig	2021-11-15 21:19:46 UTC
+++ asio/asio/ssl/detail/openssl_types.hpp
@@ -17,6 +17,10 @@
 
 #include "asio/detail/config.hpp"
 #include <openssl/conf.h>
+/* Workaround for libressl 3.4.1 and maybe earlier: The
+ * SSL_CTX gets only forward declared unless LIBRESSL_INTERNAL
+ * is defined before including ssl.h header. */
+#define LIBRESSL_INTERNAL
 #include <openssl/ssl.h>
 #if !defined(OPENSSL_NO_ENGINE)
 # include <openssl/engine.h>
