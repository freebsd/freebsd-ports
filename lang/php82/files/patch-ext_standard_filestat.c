--- ext/standard/filestat.c.orig	2024-01-17 22:33:41 UTC
+++ ext/standard/filestat.c
@@ -315,7 +315,11 @@ PHPAPI int php_get_gid_by_name(const char *name, gid_t
 		char *grbuf;
 
 		if (grbuflen < 1) {
+#if defined(__FreeBSD__) && defined(_SC_PAGESIZE)
+			grbuflen = sysconf(_SC_PAGESIZE);
+#else
 			return FAILURE;
+#endif
 		}
 
 		grbuf = emalloc(grbuflen);
@@ -441,7 +445,11 @@ PHPAPI uid_t php_get_uid_by_name(const char *name, uid
 		char *pwbuf;
 
 		if (pwbuflen < 1) {
+#if defined(__FreeBSD__) && defined(_SC_PAGESIZE)
+			pwbuflen = sysconf(_SC_PAGESIZE);
+#else
 			return FAILURE;
+#endif
 		}
 
 		pwbuf = emalloc(pwbuflen);
