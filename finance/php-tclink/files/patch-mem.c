--- mem.c.orig	2016-04-15 21:50:16 UTC
+++ mem.c
@@ -83,7 +83,7 @@ X509_LOOKUP_METHOD x509_mem_lookup =
 	NULL
 };
 
-static X509_LOOKUP_METHOD * X509_LOOKUP_mem()
+static X509_LOOKUP_METHOD * _X509_LOOKUP_mem()
 {
 	return (&x509_mem_lookup);
 }
@@ -149,12 +149,12 @@ err:
 
 }
 
-static int X509_STORE_load_mem(X509_STORE *ctx, const char *str)
+static int _X509_STORE_load_mem(X509_STORE *ctx, const char *str)
 {
 	X509_LOOKUP *lookup;
 	if (!str) return 1;
 	
-	lookup = X509_STORE_add_lookup(ctx, X509_LOOKUP_mem());
+	lookup = X509_STORE_add_lookup(ctx, _X509_LOOKUP_mem());
 	if (lookup == NULL) return 0;
 	if (X509_LOOKUP_ctrl(lookup,X509_L_FILE_LOAD,str,X509_FILETYPE_PEM, NULL) != 1)
 		return 0;
@@ -162,5 +162,5 @@ static int X509_STORE_load_mem(X509_STOR
 }
 int SSL_CTX_load_verify_locations_mem(SSL_CTX * ctx, const char *str)
 {
-	return X509_STORE_load_mem(ctx->cert_store, str);
+	return _X509_STORE_load_mem(ctx->cert_store, str);
 }
