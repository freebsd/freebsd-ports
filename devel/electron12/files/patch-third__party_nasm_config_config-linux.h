--- third_party/nasm/config/config-linux.h.orig	2021-01-07 00:39:33 UTC
+++ third_party/nasm/config/config-linux.h
@@ -139,7 +139,7 @@
 #define HAVE_ACCESS 1
 
 /* Define to 1 if you have the `canonicalize_file_name' function. */
-#define HAVE_CANONICALIZE_FILE_NAME 1
+/* #undef HAVE_CANONICALIZE_FILE_NAME */
 
 /* Define to 1 if you have the `cpu_to_le16' intrinsic function. */
 /* #undef HAVE_CPU_TO_LE16 */
@@ -183,7 +183,7 @@
 #define HAVE_DECL_STRSEP 1
 
 /* Define to 1 if you have the <endian.h> header file. */
-#define HAVE_ENDIAN_H 1
+/* #undef HAVE_ENDIAN_H */
 
 /* Define to 1 if you have the `faccessat' function. */
 #define HAVE_FACCESSAT 1
@@ -411,7 +411,7 @@
 #define HAVE_SYSCONF 1
 
 /* Define to 1 if you have the <sys/endian.h> header file. */
-/* #undef HAVE_SYS_ENDIAN_H */
+#define HAVE_SYS_ENDIAN_H 1
 
 /* Define to 1 if you have the <sys/mman.h> header file. */
 #define HAVE_SYS_MMAN_H 1
