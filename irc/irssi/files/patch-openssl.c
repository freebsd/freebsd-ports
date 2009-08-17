--- src/core/network-openssl.c.orig	2009-08-17 09:27:52.000000000 +0800
+++ src/core/network-openssl.c	2009-08-17 09:28:14.000000000 +0800
@@ -230,7 +230,7 @@
 	SSL_library_init();
 	SSL_load_error_strings();
 
-	ssl_ctx = SSL_CTX_new(SSLv23_client_method());
+	ssl_ctx = SSL_CTX_new(SSLv3_client_method());
 	if(!ssl_ctx)
 	{
 		g_error("Initialization of the SSL library failed");
@@ -259,7 +259,7 @@
 
 	if (mycert && *mycert) {
 		char *scert = NULL, *spkey = NULL;
-		if ((ctx = SSL_CTX_new(SSLv23_client_method())) == NULL) {
+		if ((ctx = SSL_CTX_new(SSLv3_client_method())) == NULL) {
 			g_error("Could not allocate memory for SSL context");
 			return NULL;
 		}
@@ -279,7 +279,7 @@
 	if ((cafile && *cafile) || (capath && *capath)) {
 		char *scafile = NULL;
 		char *scapath = NULL;
-		if (! ctx && (ctx = SSL_CTX_new(SSLv23_client_method())) == NULL) {
+		if (! ctx && (ctx = SSL_CTX_new(SSLv3_client_method())) == NULL) {
 			g_error("Could not allocate memory for SSL context");
 			return NULL;
 		}
