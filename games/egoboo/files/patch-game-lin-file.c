--- lin-file.c.orig	2019-06-15 14:41:01 UTC
+++ lin-file.c
@@ -8,7 +8,8 @@
 #include <glob.h>
 #include <sys/types.h>
 #include <sys/stat.h>
-#include <sys/dir.h>
+#include <dirent.h>
+#include <sys/syslimits.h>
 
 //File Routines-----------------------------------------------------------
 void fs_init()
