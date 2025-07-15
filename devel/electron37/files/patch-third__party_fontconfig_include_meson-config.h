--- third_party/fontconfig/include/meson-config.h.orig	2025-06-30 07:04:30 UTC
+++ third_party/fontconfig/include/meson-config.h
@@ -17,7 +17,7 @@
 
 #define FC_CACHEDIR "/var/cache/fontconfig"
 
-#define FC_DEFAULT_FONTS "\t<dir>/usr/share/fonts</dir>\n\t<dir>/usr/local/share/fonts</dir>\n"
+#define FC_DEFAULT_FONTS "\t<dir>/usr/X11R6/lib/X11/fonts</dir>\n"
 
 #define FC_FONTPATH ""
 
@@ -92,10 +92,13 @@
 
 #define HAVE_RANDOM 1
 
-#define HAVE_RANDOM_R 1
+/* #undef HAVE_RANDOM_R */
 
 #define HAVE_RAND_R 1
 
+/* Define to 1 if you have the `arc4_random' function. */
+#define HAVE_ARC4RANDOM 1
+
 #define HAVE_READLINK 1
 
 #define HAVE_STDATOMIC_PRIMITIVES 1
@@ -122,7 +125,7 @@
 
 #define HAVE_SYS_PARAM_H 1
 
-#define HAVE_SYS_STATFS_H 1
+/* #undef HAVE_SYS_STATFS_H */
 
 #define HAVE_SYS_STATVFS_H 1
 
@@ -130,7 +133,7 @@
 
 #define HAVE_SYS_TYPES_H 1
 
-#define HAVE_SYS_VFS_H 1
+/* #undef HAVE_SYS_VFS_H */
 
 #define HAVE_TIME_H 1
 
