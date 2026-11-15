--- third_party/nasm/config/config-linux.h.orig	2026-06-23 23:37:18 UTC
+++ third_party/nasm/config/config-linux.h
@@ -220,7 +220,7 @@
 #define HAVE_DECL_STRSEP 1
 
 /* Define to 1 if you have the <endian.h> header file. */
-#define HAVE_ENDIAN_H 1
+/* #undef HAVE_ENDIAN_H */
 
 /* Define to 1 if you have the 'faccessat' function. */
 #define HAVE_FACCESSAT 1
@@ -399,13 +399,13 @@
 #define HAVE_ISASCII 1
 
 /* Define to 1 if you have the 'iscntrl' function. */
-/* #undef HAVE_ISCNTRL */
+#define HAVE_ISCNTRL 1
 
 /* Define to 1 if you have the <machine/endian.h> header file. */
-/* #undef HAVE_MACHINE_ENDIAN_H */
+#define HAVE_MACHINE_ENDIAN_H 1
 
 /* Define to 1 if you have the 'mempcpy' function. */
-#define HAVE_MEMPCPY 1
+/* #undef HAVE_MEMPCPY */
 
 /* Define to 1 if you have the 'mempset' function. */
 /* #undef HAVE_MEMPSET */
@@ -435,7 +435,7 @@
 /* #undef HAVE_STDBIT_H */ // Controlled by the Chromium build process - see generate_nasm_configs.py
 
 /* Define to 1 if stdbool.h conforms to C99. */
-/* #undef HAVE_STDBOOL_H */
+#define HAVE_STDBOOL_H 1
 
 /* Define to 1 if your compiler supports C99 extern inline */
 #define HAVE_STDC_INLINE 1
@@ -468,7 +468,7 @@
 #define HAVE_STRING_H 1
 
 /* Define to 1 if you have the 'strlcpy' function. */
-/* #undef HAVE_STRLCPY */ // Shouldn\'t work with -std=c11, but configure still detects it.
+#define HAVE_STRLCPY 1
 
 /* Define to 1 if you have the 'strncasecmp' function. */
 #define HAVE_STRNCASECMP 1
@@ -495,7 +495,7 @@
 #define HAVE_SYSCONF 1
 
 /* Define to 1 if you have the <sys/endian.h> header file. */
-/* #undef HAVE_SYS_ENDIAN_H */
+#define HAVE_SYS_ENDIAN_H 1
 
 /* Define to 1 if you have the <sys/mman.h> header file. */
 #define HAVE_SYS_MMAN_H 1
