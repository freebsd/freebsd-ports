--- config.h.orig	Sat Dec  4 17:43:47 2004
+++ config.h	Sat Dec  4 17:44:04 2004
@@ -47,9 +47,9 @@
 #define PART_QUIT_MSG_LEN 256
 #define CTCP_VERSION_REPLY "Netwalker IRC-Client"
 
-#define FILES_HELP_DIRECTORY       "/usr/share/netwalker-ircc/"
+#define FILES_HELP_DIRECTORY       "%%PREFIX%%/share/netwalker-ircc/"
 #define FILES_HELP_INDEX_FILE      "/helpindex.asc"
-#define FILES_CONFIG_FILE          "/.netwalkerircc.conf"
+#define FILES_CONFIG_FILE          "/.netwalkerircc"
 
 /* some default values */
 #define DEFAULT_NICKNAME           "ABC"
