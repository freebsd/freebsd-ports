--- main/fopen_wrappers.c.orig	2024-01-17 22:12:12 UTC
+++ main/fopen_wrappers.c
@@ -381,7 +381,11 @@ PHPAPI int php_fopen_primary_script(zend_file_handle *
 			char *pwbuf;
 
 			if (pwbuflen < 1) {
+#if defined(__FreeBSD__) && defined(_SC_PAGESIZE)
+				pwbuflen = sysconf(_SC_PAGESIZE);
+#else
 				return FAILURE;
+#endif
 			}
 
 			pwbuf = emalloc(pwbuflen);
