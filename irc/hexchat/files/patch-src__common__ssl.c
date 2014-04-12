--- ./src/common/ssl.c.orig	2013-09-12 00:18:19.000000000 +0200
+++ ./src/common/ssl.c	2014-04-12 16:06:12.028592630 +0200
@@ -305,7 +305,7 @@
 		__SSL_fill_err_buf ("SSL_CTX_set_default_verify_paths");
 		return (err_buf);
 	}
-/*
+
 	if (cacert)
 	{
 		if (!SSL_CTX_load_verify_locations (ctx, cacert, NULL))
@@ -314,7 +314,7 @@
 			return (err_buf);
 		}
 	}
-*/
+
 	SSL_CTX_set_verify (ctx, SSL_VERIFY_PEER, verify_callback);
 
 	return (NULL);
