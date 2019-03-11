--- sail/pathnames.h.orig	2019-03-07 20:11:21 UTC
+++ sail/pathnames.h
@@ -31,6 +31,6 @@
  *	@(#)pathnames.h	8.1 (Berkeley) 5/31/93
  */
 
-#define	_PATH_LOGFILE	"@sail_scorefile@"
-#define	_PATH_SYNC	"@sail_dir@/#sailsink.%d"
-#define	_PATH_LOCK	"@sail_dir@/#saillock.%d"
+#define	_PATH_LOGFILE	"/var/games/saillog"
+#define	_PATH_SYNC	"/tmp/#sailsink.%d"
+#define	_PATH_LOCK	"/tmp/#saillock.%d"
