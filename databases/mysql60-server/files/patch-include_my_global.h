--- include/my_global.h.orig	Mon Jul  2 08:06:55 2007
+++ include/my_global.h	Mon Jul  2 08:07:53 2007
@@ -561,12 +561,6 @@
 #define PURIFY_OR_LINT_INIT(var)
 #endif
 
-/* Define some useful general macros */
-#if !defined(max)
-#define max(a, b)	((a) > (b) ? (a) : (b))
-#define min(a, b)	((a) < (b) ? (a) : (b))
-#endif
-
 #if !defined(HAVE_UINT)
 #undef HAVE_UINT
 #define HAVE_UINT
@@ -1508,5 +1502,11 @@
 
 /* Length of decimal number represented by INT64. */
 #define MY_INT64_NUM_DECIMAL_DIGITS 21
+
+/* Define some useful general macros */
+#if !defined(max)
+#define max(a, b)	((a) > (b) ? (a) : (b))
+#define min(a, b)	((a) < (b) ? (a) : (b))
+#endif
 
 #endif /* my_global_h */
