--- main/fopen_wrappers.c.orig	2024-01-17 22:32:57 UTC
+++ main/fopen_wrappers.c
@@ -369,7 +369,11 @@ PHPAPI int php_fopen_primary_script(zend_file_handle *
 			char *pwbuf;
 
 			if (pwbuflen < 1) {
+#if defined(__FreeBSD__) && defined(_SC_PAGESIZE)
+				buflen = sysconf(_SC_PAGESIZE);
+#else
 				return FAILURE;
+#endif
 			}
 
 			pwbuf = emalloc(pwbuflen);
