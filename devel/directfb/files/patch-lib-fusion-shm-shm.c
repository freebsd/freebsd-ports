--- lib/fusion/shm/shm.c.orig	2012-05-23 13:43:12 UTC
+++ lib/fusion/shm/shm.c
@@ -34,7 +34,7 @@
 #include <sys/param.h>
 #include <sys/types.h>
 #include <sys/stat.h>
-#include <sys/vfs.h>
+#include <sys/mount.h>
 
 #include <direct/debug.h>
 #include <direct/list.h>
