--- src/common/ssl.c.orig	2016-12-10 14:30:51 UTC
+++ src/common/ssl.c
@@ -328,7 +328,7 @@ _SSL_set_verify (SSL_CTX *ctx, void *ver
 		__SSL_fill_err_buf ("SSL_CTX_set_default_verify_paths");
 		return (err_buf);
 	}
-/*
+
 	if (cacert)
 	{
 		if (!SSL_CTX_load_verify_locations (ctx, cacert, NULL))
@@ -337,7 +337,7 @@ _SSL_set_verify (SSL_CTX *ctx, void *ver
 			return (err_buf);
 		}
 	}
-*/
+
 	SSL_CTX_set_verify (ctx, SSL_VERIFY_PEER, verify_callback);
 
 	return (NULL);
