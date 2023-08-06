--- modules/openssl/stream_peer_openssl.cpp.orig	2023-08-06 17:18:41 UTC
+++ modules/openssl/stream_peer_openssl.cpp
@@ -596,7 +596,9 @@ void StreamPeerOpenSSL::initialize_ssl() {
 #endif
 	SSL_library_init(); // Initialize OpenSSL's SSL libraries
 	SSL_load_error_strings(); // Load SSL error strings
+#if OPENSSL_VERSION_NUMBER < 0x30000000L
 	ERR_load_BIO_strings(); // Load BIO error strings
+#endif
 	OpenSSL_add_all_algorithms(); // Load all available encryption algorithms
 	String certs_path = GLOBAL_DEF("ssl/certificates", "");
 	Globals::get_singleton()->set_custom_property_info("ssl/certificates", PropertyInfo(Variant::STRING, "ssl/certificates", PROPERTY_HINT_FILE, "*.crt"));
