--- third_party/fontconfig/include/config.h.orig	2024-04-15 20:34:24 UTC
+++ third_party/fontconfig/include/config.h
@@ -13,7 +13,7 @@
 
 #define FC_CACHEDIR "/var/cache/fontconfig"
 
-#define FC_DEFAULT_FONTS "\t<dir>/usr/share/fonts</dir>\n\t<dir>/usr/local/share/fonts</dir>\n"
+#define FC_DEFAULT_FONTS "\t<dir>/usr/X11R6/lib/X11/fonts</dir>"
 
 #define FC_FONTPATH ""
 
@@ -66,7 +66,7 @@
 
 #define HAVE_MMAP 1
 
-#define HAVE_POSIX_FADVISE 1
+#define HAVE_POSIX_FADVISE 0
 
 #define HAVE_PTHREAD 1
 
@@ -74,10 +74,13 @@
 
 #define HAVE_RANDOM 1
 
-#define HAVE_RANDOM_R 1
+/* #undef HAVE_RANDOM_R */
 
 #define HAVE_RAND_R 1
 
+/* Define to 1 if you have the `arc4_random' function. */
+#define HAVE_ARC4RANDOM 1
+
 #define HAVE_READLINK 1
 
 #define HAVE_STDATOMIC_PRIMITIVES 1
@@ -92,11 +95,11 @@
 
 #define HAVE_SYS_PARAM_H 1
 
-#define HAVE_SYS_STATFS_H 1
+/* #undef HAVE_SYS_STATFS_H */
 
 #define HAVE_SYS_STATVFS_H 1
 
-#define HAVE_SYS_VFS_H 1
+/* #undef HAVE_SYS_VFS_H */
 
 #define HAVE_UNISTD_H 1
 
