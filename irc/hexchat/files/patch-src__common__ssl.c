--- src/common/ssl.c.orig	2014-07-28 19:47:50 UTC
+++ src/common/ssl.c
@@ -310,7 +310,7 @@
 		__SSL_fill_err_buf ("SSL_CTX_set_default_verify_paths");
 		return (err_buf);
 	}
-/*
+
 	if (cacert)
 	{
 		if (!SSL_CTX_load_verify_locations (ctx, cacert, NULL))
@@ -319,7 +319,7 @@
 			return (err_buf);
 		}
 	}
-*/
+
 	SSL_CTX_set_verify (ctx, SSL_VERIFY_PEER, verify_callback);
 
 	return (NULL);
