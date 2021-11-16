--- galerautils/src/gu_asio_stream_engine.cpp.orig	2021-11-15 21:09:11 UTC
+++ galerautils/src/gu_asio_stream_engine.cpp
@@ -100,7 +100,7 @@ class AsioTcpStreamEngine : public gu::AsioStreamEngin
 
 #include <openssl/ssl.h>
 
-#if OPENSSL_VERSION_NUMBER >= 0x1010100fL
+#if OPENSSL_VERSION_NUMBER >= 0x1010100fL && !defined(LIBRESSL_VERSION_NUMBER)
 #define HAVE_READ_EX
 #define HAVE_WRITE_EX
 #endif
