--- src/ftpd.c-orig	Tue Feb  3 18:16:46 2004
+++ src/ftpd.c	Tue Feb  3 18:19:26 2004
@@ -436,6 +436,7 @@
 	if (EMPTYSTR(confdir))
 		confdir = _DEFAULT_CONFDIR;
 
+#ifdef _SC_LOGIN_NAME_MAX
 	errno = 0;
 	l = sysconf(_SC_LOGIN_NAME_MAX);
 	if (l == -1 && errno != 0) {
@@ -446,6 +447,9 @@
 		curname_len = _POSIX_LOGIN_NAME_MAX;
 	} else 
 		curname_len = (size_t)l;
+#else
+	curname_len = LOGIN_NAME_MAX;
+#endif
 	curname = malloc(curname_len);
 	if (curname == NULL) {
 		syslog(LOG_ERR, "malloc: %m");
