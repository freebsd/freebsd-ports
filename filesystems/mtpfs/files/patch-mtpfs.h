--- mtpfs.h.orig	2016-12-15 23:55:52 UTC
+++ mtpfs.h
@@ -17,7 +17,7 @@
 #include <fcntl.h>
 #include <dirent.h>
 #include <errno.h>
-#include <sys/statfs.h>
+#include <sys/mount.h>
 
 #include <libmtp.h>
 #include <glib.h>
