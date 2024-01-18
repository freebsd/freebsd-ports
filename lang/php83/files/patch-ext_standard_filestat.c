--- ext/standard/filestat.c.orig	2024-01-17 22:13:37 UTC
+++ ext/standard/filestat.c
@@ -281,7 +281,11 @@ PHPAPI zend_result php_get_gid_by_name(const char *nam
 		char *grbuf;
 
 		if (grbuflen < 1) {
+#if defined(__FreeBSD__) && defined(_SC_PAGESIZE)
+			grbuflen = sysconf(_SC_PAGESIZE);
+#else
 			return FAILURE;
+#endif
 		}
 
 		grbuf = emalloc(grbuflen);
@@ -407,7 +411,11 @@ PHPAPI zend_result php_get_uid_by_name(const char *nam
 		char *pwbuf;
 
 		if (pwbuflen < 1) {
+#if defined(__FreeBSD__) && defined(_SC_PAGESIZE)
+			pwbuflen = sysconf(_SC_PAGESIZE);
+#else
 			return FAILURE;
+#endif
 		}
 
 		pwbuf = emalloc(pwbuflen);
