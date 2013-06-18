--- lin-file.c.orig	2007-11-16 22:36:58.000000000 +0300
+++ lin-file.c	2008-02-07 04:09:32.000000000 +0300
@@ -9,6 +9,7 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <sys/dir.h>
+#include <sys/syslimits.h>
 
 //File Routines-----------------------------------------------------------
 void fs_init()
