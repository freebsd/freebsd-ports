--- usr/include/linux/stat.h.orig	2011-07-17 20:54:19.000000000 +0200
+++ usr/include/linux/stat.h	2011-07-17 20:55:15.000000000 +0200
@@ -39,6 +39,9 @@
 #define S_IWUSR 00200
 #define S_IXUSR 00100
 
+#define S_IREAD  S_IRUSR
+#define S_IWRITE S_IWUSR
+
 #define S_IRWXG 00070
 #define S_IRGRP 00040
 #define S_IWGRP 00020
