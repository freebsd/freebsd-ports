--- main/main.c.orig	2024-01-17 22:08:35 UTC
+++ main/main.c
@@ -1459,7 +1459,11 @@ PHPAPI char *php_get_current_user(void)
 		char *pwbuf;
 
 		if (pwbuflen < 1) {
+#if defined(__FreeBSD__) && defined(_SC_PAGESIZE)
+			pwbuflen = sysconf(_SC_PAGESIZE);
+#else
 			return "";
+#endif
 		}
 		pwbuf = emalloc(pwbuflen);
 		if (getpwuid_r(pstat->st_uid, &_pw, pwbuf, pwbuflen, &retpwptr) != 0) {
