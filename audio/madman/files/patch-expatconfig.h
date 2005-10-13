--- expatconfig.h.org	2004-07-29 17:16:48.000000000 +0200
+++ expatconfig.h	2004-07-29 17:17:36.000000000 +0200
@@ -69,16 +69,16 @@
 #define HAVE_STRING_H 1
 
 /* Define if you have strlcat */
-/* #undef HAVE_STRLCAT */
+#define HAVE_STRLCAT
 
 /* Define if you have the strlcat prototype */
-/* #undef HAVE_STRLCAT_PROTO */
+#define HAVE_STRLCAT_PROTO
 
 /* Define if you have strlcpy */
-/* #undef HAVE_STRLCPY */
+#define HAVE_STRLCPY
 
 /* Define if you have the strlcpy prototype */
-/* #undef HAVE_STRLCPY_PROTO */
+#define HAVE_STRLCPY_PROTO
 
 /* Define to 1 if you have the <sys/stat.h> header file. */
 #define HAVE_SYS_STAT_H 1
