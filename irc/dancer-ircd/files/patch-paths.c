--- src/paths.c.orig	Sat Nov  8 01:28:44 2003
+++ src/paths.c	Tue Apr 20 00:33:19 2004
@@ -64,20 +64,20 @@
  */
 
 #define DPATH    PREFIX "/"
-#define SPATH    "sbin/dancer-ircd"
-#define CPATH    "etc/dancer-ircd/ircd.conf"
-#define MPATH    "etc/dancer-ircd/motd"
-#define HPATH    "etc/dancer-ircd/ohelp"
-#define OPATH    "etc/dancer-ircd/omotd"
-#define LPATH    "var/log/dancer-ircd/ircd.log"
-#define HLBASE   "var/log/dancer-ircd/hash"
-#define USERLOG  "var/log/dancer-ircd/user.log"
-#define OPERLOG  "var/log/dancer-ircd/oper.log"
-#define PPATH    "var/run/dancer-ircd/dancer-ircd.pid"
-#define KPATH    "var/lib/dancer-ircd/kline.conf"
-#define DLPATH   "var/lib/dancer-ircd/dline.conf"
-#define MXPATH   "var/lib/dancer-ircd/ircd.max"
-#define DUMPPATH "var/lib/dancer-ircd/dump"
+#define SPATH    "/usr/local/sbin/dancer-ircd"
+#define CPATH    "/usr/local/etc/dancer-ircd/ircd.conf"
+#define MPATH    "/usr/local/etc/dancer-ircd/motd"
+#define HPATH    "/usr/local/etc/dancer-ircd/ohelp"
+#define OPATH    "/usr/local/etc/dancer-ircd/omotd"
+#define LPATH    "/var/log/dancer-ircd/ircd.log"
+#define HLBASE   "/var/log/dancer-ircd/hash"
+#define USERLOG  "/var/log/dancer-ircd/user.log"
+#define OPERLOG  "/var/log/dancer-ircd/oper.log"
+#define PPATH    "/var/run/dancer-ircd/dancer-ircd.pid"
+#define KPATH    "/usr/local/etc/dancer-ircd/kline.conf"
+#define DLPATH   "/usr/local/etc/dancer-ircd/dline.conf"
+#define MXPATH   "/usr/local/etc/dancer-ircd/ircd.max"
+#define DUMPPATH "/usr/local/etc/dancer-ircd/dump"
 
 const char *work_dir = DPATH;
 const char *config_file = CPATH;
