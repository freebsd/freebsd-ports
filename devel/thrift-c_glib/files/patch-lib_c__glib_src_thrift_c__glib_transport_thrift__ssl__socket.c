--- lib/c_glib/src/thrift/c_glib/transport/thrift_ssl_socket.c.orig	2023-08-07 02:22:44 UTC
+++ lib/c_glib/src/thrift/c_glib/transport/thrift_ssl_socket.c
@@ -86,7 +86,7 @@ static unsigned long thrift_ssl_socket_static_id_funct
 #endif
 }
 
-static void thrift_ssl_socket_static_locking_callback(int mode, int n, const char* unk, int id) 
+static void thrift_ssl_socket_static_locking_callback(int mode, int n, const char* unk, int id)
 {
   THRIFT_UNUSED_VAR (unk);
   THRIFT_UNUSED_VAR (id);
@@ -380,7 +380,7 @@ gboolean
 thrift_ssl_socket_flush (ThriftTransport *transport, GError **error)
 {
   ThriftSSLSocket *ssl_socket = THRIFT_SSL_SOCKET (transport);
- 
+
   ThriftSocket *socket = THRIFT_SOCKET (transport);
 
   ThriftTransportClass *ttc = THRIFT_TRANSPORT_GET_CLASS (transport);
@@ -675,7 +675,9 @@ thrift_ssl_socket_initialize_openssl(void)
   SSL_library_init();
   ERR_load_crypto_strings();
   SSL_load_error_strings();
+#if OPENSSL_VERSION_NUMBER < 0x30000000L
   ERR_load_BIO_strings();
+#endif
 
   /* Setup locking */
   g_debug("We setup %d threads locks", thrift_ssl_socket_static_thread_setup());
@@ -867,4 +869,3 @@ thrift_ssl_socket_context_initialize(ThriftSSLSocketPr
 
   return context;
 }
-
