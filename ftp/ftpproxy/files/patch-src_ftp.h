--- src/ftp.h.orig	2023-02-20 11:42:14 UTC
+++ src/ftp.h
@@ -29,11 +29,19 @@
 #ifndef	_FTP_INCLUDED
 #define	_FTP_INCLUDED
 
+#include <limits.h>
+#include <libutil.h>
+
 extern char *version;
 
 extern char *program;
-extern char progname[80];
+extern char progname[PATH_MAX];
 
+/* PID file */
+#define PIDFILE_DEFAULT "/var/run/ftpproxy.pid"
+extern char pidfile[PATH_MAX];
+extern struct pidfh *pfh;
+
 extern int debug;
 extern int extralog;
 extern int bindport;
@@ -45,7 +53,7 @@ extern int acceptloop(int sock);
 
 
 typedef struct _config {
-    char	configfile[200];
+    char	configfile[PATH_MAX];
 
     int		standalone;
     int		timeout;
@@ -53,12 +61,12 @@ typedef struct _config {
     int		selectserver;
     int		allow_anyremote;
 
-    char	server[200];
+    char	server[NI_MAXHOST];
     char	*serverlist;
 
-    char	acp[200];
-    char	ccp[200];
-    char	ctp[200];
+    char	acp[PATH_MAX];
+    char	ccp[PATH_MAX];
+    char	ctp[PATH_MAX];
     char	varname[80];
 
     int		allow_blanks;
@@ -66,10 +74,10 @@ typedef struct _config {
     int		use_last_at;
     int		monitor;
     int		bsize;
-    char	xferlog[200];
+    char	xferlog[PATH_MAX];
 
     int		numeric_only;
-    char	sourceip[200];
+    char	sourceip[NI_MAXHOST];
     unsigned int dataport;
     } config_t;
 
