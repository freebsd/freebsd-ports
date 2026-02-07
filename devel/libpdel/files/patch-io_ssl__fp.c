--- io/ssl_fp.c.orig	2023-08-08 07:48:05 UTC
+++ io/ssl_fp.c
@@ -361,8 +361,10 @@ ssl_log(ssl_logger_t *logger, void *logarg)
 			strlcat(buf, t, sizeof(buf));
 			strlcat(buf, ": ", sizeof(buf));
 		} else {
+#if OPENSSL_VERSION_NUMBER < 0x30000000L
 			snprintf(buf + strlen(buf), sizeof(buf) - strlen(buf),
 			    "func=%u: ", ERR_GET_FUNC(e));
+#endif
 		}
 
 		/* Add reason */
@@ -388,4 +390,3 @@ null_logger(void *arg, int sev, const char *fmt, ...)
 {
 	return;
 }
-
