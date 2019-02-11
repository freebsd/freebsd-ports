--- daemon/remote.c.orig	2019-01-23 09:35:52 UTC
+++ daemon/remote.c
@@ -1987,7 +1987,7 @@ parse_delegpt(RES* ssl, char* args, uint8_t* nm, int a
 				return NULL;
 			}
 		} else {
-#ifndef HAVE_SSL_SET1_HOST
+#if ! defined(HAVE_SSL_SET1_HOST) && ! defined(HAVE_X509_VERIFY_PARAM_SET1_HOST)
 			if(auth_name)
 			  log_err("no name verification functionality in "
 				"ssl library, ignored name for %s", todo);
