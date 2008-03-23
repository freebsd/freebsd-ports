--- Wnn/etc/bdic.c.orig	2007-11-11 17:46:42.000000000 +0900
+++ Wnn/etc/bdic.c	2007-11-11 17:47:41.000000000 +0900
@@ -1015,9 +1015,6 @@
 #ifdef WNN_CHECK_INODE
 static
 #else 
-#ifdef JS
-static
-#endif
 #endif 
 int
 change_file_uniq1(ofpter, file_type, file_passwd, file_uniq)
