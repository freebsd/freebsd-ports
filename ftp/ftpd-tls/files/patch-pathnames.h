--- pathnames.h.orig	Fri May  3 10:15:39 2002
+++ pathnames.h	Tue Sep  9 02:34:05 2003
@@ -40,12 +40,13 @@
 #include <paths.h>
 #endif /* HAVE_PATHS_H */
 
-#define	_PATH_FTPUSERS		"/etc/ftpusers"
-#define	_PATH_FTPCHROOT		"/etc/ftpchroot"
-#define	_PATH_FTPWELCOME	"/etc/ftpwelcome"
-#define	_PATH_FTPLOGINMESG	"/etc/motd"
-#define _PATH_FTPDSTATFILE	"/var/log/ftpd"
-#define _PATH_FTPDPID		"/var/run/ftpd.pid"
+#undef	_PATH_FTPUSERS
+#define	_PATH_FTPUSERS		"%%PREFIX%%/etc/ftpd-tls/ftpusers"
+#define	_PATH_FTPCHROOT		"%%PREFIX%%/etc/ftpd-tls/ftpchroot"
+#define	_PATH_FTPWELCOME	"%%PREFIX%%/etc/ftpd-tls/ftpwelcome"
+#define	_PATH_FTPLOGINMESG	"%%PREFIX%%/etc/ftpd-tls/motd"
+#define _PATH_FTPDSTATFILE	"/var/log/ftpd-tls"
+#define _PATH_FTPDPID		"/var/run/ftpd-tls.pid"
 #define _PATH_CWDMESG		".message"
 #ifndef _PATH_NOLOGIN
 #define _PATH_NOLOGIN		"/etc/nologin"
