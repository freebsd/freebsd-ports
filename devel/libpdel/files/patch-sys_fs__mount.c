--- sys/fs_mount.c.orig	2009-05-13 21:36:05 UTC
+++ sys/fs_mount.c
@@ -9,6 +9,8 @@
 #include <sys/param.h>
 #include <sys/mount.h>
 
+#include <ufs/ufs/quota.h>
+#include <ufs/ufs/extattr.h>
 #include <ufs/ufs/ufsmount.h>
 
 #include <stdio.h>
