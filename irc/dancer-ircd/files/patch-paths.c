--- src/paths.c.orig	Tue Jul  8 14:41:55 2003
+++ src/paths.c	Fri Nov 14 05:26:16 2003
@@ -64,20 +64,21 @@
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
-#define PPATH    "var/run/dancer-ircd.pid"
-#define KPATH    "var/lib/dancer-ircd/kline.conf"
-#define DLPATH   "var/lib/dancer-ircd/dline.conf"
-#define MXPATH   "var/lib/dancer-ircd/ircd.max"
-#define DUMPPATH "var/lib/dancer-ircd/dump"
+
+#define SPATH    "@@prefix@@/bin/dancer-ircd"
+#define CPATH    "@@prefix@@/etc/dancer-ircd/ircd.conf"
+#define MPATH    "@@prefix@@/etc/dancer-ircd/motd"
+#define HPATH    "@@prefix@@/etc/dancer-ircd/ohelp"
+#define OPATH    "@@prefix@@/etc/dancer-ircd/omotd"
+#define LPATH    "/var/log/dancer-ircd/ircd.log"
+#define HLBASE   "/var/log/dancer-ircd/hash"
+#define USERLOG  "/var/log/dancer-ircd/user.log"
+#define OPERLOG  "/var/log/dancer-ircd/oper.log"
+#define PPATH    "/var/run/dancer-ircd/dancer-ircd.pid"
+#define KPATH    "@@prefix@@/etc/dancer-ircd/kline.conf"
+#define DLPATH   "@@prefix@@/etc/dancer-ircd/dline.conf"
+#define MXPATH   "@@prefix@@/etc/dancer-ircd/ircd.max"
+#define DUMPPATH "@@prefix@@/etc/dancer-ircd/dump"
 
 const char *work_dir = DPATH;
 const char *config_file = CPATH;
