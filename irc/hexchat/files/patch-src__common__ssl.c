--- src/common/ssl.c.orig	2014-11-25 18:42:31.000000000 +0100
+++ src/common/ssl.c	2015-05-21 15:58:31.403630733 +0200
@@ -320,7 +320,7 @@
 		__SSL_fill_err_buf ("SSL_CTX_set_default_verify_paths");
 		return (err_buf);
 	}
-/*
+
 	if (cacert)
 	{
 		if (!SSL_CTX_load_verify_locations (ctx, cacert, NULL))
@@ -329,7 +329,7 @@
 			return (err_buf);
 		}
 	}
-*/
+
 	SSL_CTX_set_verify (ctx, SSL_VERIFY_PEER, verify_callback);
 
 	return (NULL);
