--- usr/include/linux/stat.h.orig	2014-10-15 02:53:49 UTC
+++ usr/include/linux/stat.h
@@ -57,5 +57,7 @@
 #define S_IWOTH 00002
 /* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 #define S_IXOTH 00001
+#define S_IREAD  S_IRUSR
+#define S_IWRITE S_IWUSR
 #endif
 #endif
