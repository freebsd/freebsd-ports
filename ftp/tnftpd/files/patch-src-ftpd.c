--- src/ftpd.c-orig	Wed Aug 18 17:22:30 2004
+++ src/ftpd.c	Wed Aug 18 17:27:28 2004
@@ -450,12 +450,12 @@
 		exit(1);
 	} else if (l <= 0) {
 		syslog(LOG_WARNING, "using conservative LOGIN_NAME_MAX value");
-		curname_len = _POSIX_LOGIN_NAME_MAX;
+		curname_len = LOGIN_NAME_MAX;
 	} else 
 		curname_len = (size_t)l;
 #else
 	/* using conservative LOGIN_NAME_MAX value */
-	curname_len = _POSIX_LOGIN_NAME_MAX;
+	curname_len = LOGIN_NAME_MAX;
 #endif
 	curname = malloc(curname_len);
 	if (curname == NULL) {
