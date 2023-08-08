--- third_party/fontconfig/include/config.h.orig	2022-02-07 13:39:41 UTC
+++ third_party/fontconfig/include/config.h
@@ -18,13 +18,13 @@
 #define ENABLE_NLS 1
 
 /* Additional font directories */
-#define FC_ADD_FONTS "yes"
+#define FC_ADD_FONTS "/usr/local/share/fonts"     
 
 /* Architecture prefix to use for cache file names */
 /* #undef FC_ARCHITECTURE */
 
 /* System font directory */
-#define FC_DEFAULT_FONTS "/usr/share/fonts"
+#define FC_DEFAULT_FONTS "/usr/X11R6/lib/X11/fonts"
 
 /* The type of len parameter of the gperf hash/lookup function */
 #define FC_GPERF_SIZE_T size_t
@@ -100,7 +100,7 @@
 #define HAVE_GETPAGESIZE 1
 
 /* Define to 1 if you have the `getprogname' function. */
-/* #undef HAVE_GETPROGNAME */
+#define HAVE_GETPROGNAME 1
 
 /* Define if the GNU gettext() function is already present or preinstalled. */
 #define HAVE_GETTEXT 1
@@ -142,7 +142,7 @@
 /* #undef HAVE_NDIR_H */
 
 /* Define to 1 if you have the 'posix_fadvise' function. */
-#define HAVE_POSIX_FADVISE 1
+#define HAVE_POSIX_FADVISE 0
 
 /* Have POSIX threads */
 #define HAVE_PTHREAD 1
@@ -157,11 +157,14 @@
 #define HAVE_RANDOM 1
 
 /* Define to 1 if you have the `random_r' function. */
-#define HAVE_RANDOM_R 1
+/* #undef HAVE_RANDOM_R */
 
 /* Define to 1 if you have the `rand_r' function. */
 #define HAVE_RAND_R 1
 
+/* Define to 1 if you have the `arc4_random' function. */
+#define HAVE_ARC4RANDOM 1
+
 /* Define to 1 if you have the `readlink' function. */
 #define HAVE_READLINK 1
 
@@ -199,7 +202,7 @@
 #define HAVE_STRUCT_STATFS_F_FLAGS 1
 
 /* Define to 1 if `f_fstypename' is a member of `struct statfs'. */
-/* #undef HAVE_STRUCT_STATFS_F_FSTYPENAME */
+#define HAVE_STRUCT_STATFS_F_FSTYPENAME 1
 
 /* Define to 1 if `f_basetype' is a member of `struct statvfs'. */
 /* #undef HAVE_STRUCT_STATVFS_F_BASETYPE */
@@ -225,7 +228,7 @@
 #define HAVE_SYS_PARAM_H 1
 
 /* Define to 1 if you have the <sys/statfs.h> header file. */
-#define HAVE_SYS_STATFS_H 1
+/* #undef HAVE_SYS_STATFS_H */
 
 /* Define to 1 if you have the <sys/statvfs.h> header file. */
 #define HAVE_SYS_STATVFS_H 1
@@ -237,7 +240,7 @@
 #define HAVE_SYS_TYPES_H 1
 
 /* Define to 1 if you have the <sys/vfs.h> header file. */
-#define HAVE_SYS_VFS_H 1
+/* #undef HAVE_SYS_VFS_H */
 
 /* Define to 1 if you have the <unistd.h> header file. */
 #define HAVE_UNISTD_H 1
@@ -257,7 +260,8 @@
 /* Define to 1 if you have the `_mktemp_s' function. */
 /* #undef HAVE__MKTEMP_S */
 
-/* Define to the sub-directory where libtool stores uninstalled libraries. */
+/* Define to the sub-directory in which libtool stores uninstalled libraries.
+   */
 #define LT_OBJDIR ".libs/"
 
 /* Name of package */
